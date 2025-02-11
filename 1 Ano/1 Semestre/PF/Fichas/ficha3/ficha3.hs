{-|
Module      : Ficha3
Description : Módulo Haskell contendo ficha 3 de PF.
Copyright   : (c) Sívio <a100762@uminho.pt>, 2024
Stability   : experimental
Portability : POSIX

Gestão de informação em listas.
-}

import Test.HUnit

horaValida :: Hora -> Bool
horaValida (H h m) = h >= 0 && h < 24 && m >= 0 && m < 60

horaMaisTardeQue :: Hora -> Hora -> Bool
horaMaisTardeQue (H h1 m1) (H h2 m2)
    | h1 > h2 = True
    | h1 == h2 && m1 > m2 = True
    | otherwise = False

horaParaMins :: Hora -> Int
horaParaMins (H h m) = h*60 + m

minsparaHoras :: Int -> Hora
minsparaHoras min = H (div min 60) (mod min 60)

horaDiferenca :: Hora -> Hora -> Int
horaDiferenca (H h1 m1) (H h2 m2) = a `max` b - a `min` b
        where
            a = horaParaMins (H h1 m1)
            b = horaParaMins (H h2 m2)

horaADDmins :: Hora -> Int -> Hora
horaADDmins (H h m) min = minsparaHoras (horaParaMins (H h m) + min)

data Hora = H Int Int
    deriving (Show)
type Etapa = (Hora,Hora)
type Viagem = [Etapa]

etapaBem :: Etapa -> Bool
etapaBem (h1, h2) = horaValida h1 && horaValida h2
                                && horaMaisTardeQue h1 h2

viagemBem :: Viagem -> Bool
viagemBem [] = True
viagemBem ((hi1,hf1):(hi2,hf2):xs)
    | not (etapaBem (hi1,hf1)) && not (horaMaisTardeQue hi1 hi2)= False
    | otherwise = viagemBem ((hi2,hf2):xs)

horaPartida :: Viagem -> Hora
horaPartida [(x, _)] = x

horaChegada :: Viagem -> Hora
horaChegada [(_, x)] = x
horaChegada (x:xs) = horaChegada xs

inicioFimViagem :: Viagem -> [Hora]
inicioFimViagem x = [horaPartida x, horaChegada x]

duracaoEtapa :: Etapa -> Int
duracaoEtapa (i,f) = horaDiferenca i f

tempoViagemEfetiva :: Viagem -> Int
tempoViagemEfetiva [x] =  duracaoEtapa x
tempoViagemEfetiva (x:xs) = duracaoEtapa x + tempoViagemEfetiva xs

tempoTotalEspera :: Viagem -> Int
tempoTotalEspera [x] = 0
tempoTotalEspera ((_,hf1):(hi2,_):xs) = horaDiferenca hf1 hi2 + tempoTotalEspera xs

tempoTotalViagem :: Viagem -> Int
tempoTotalViagem x = tempoViagemEfetiva x + tempoTotalEspera x

data Ponto = Ponto Double Double
    deriving (Show,Eq)
data Figura =
    Circulo Ponto Double |
    Retangulo Ponto Ponto |
    Triangulo Ponto Ponto Ponto
    deriving (Show,Eq)
type Poligonal = [Ponto]

dist :: Ponto -> Ponto -> Double
dist (Ponto x1 y1) (Ponto x2 y2) = sqrt ((x1 - x2)^2 + (y1-y2)^2)

comp :: Poligonal -> Double
comp [] = 0
comp [_] = 0
comp (p1:p2:t) = dist p1 p2 + comp (p2:t)

poligonalFechada :: Poligonal -> Bool
poligonalFechada [] = False
poligonalFechada [_] = False
poligonalFechada l = head l == last l

area :: Figura -> Double
area (Triangulo p1 p2 p3) =
    let a = dist p1 p2
        b = dist p2 p3
        c = dist p3 p1
        s = (a+b+c) / 2 -- semi-perimetro
    in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron
area (Circulo (Ponto x y) r) = pi * r
area (Retangulo (Ponto x1 y1) (Ponto x2 y2)) = abs (x1 - x2) * abs (y1 - y2)

triangula :: Poligonal -> [Figura]
triangula (a:b:c:t) = Triangulo a b c : triangula (a:c:t)
triangula _ = []

somaAreas :: [Figura] -> Double
somaAreas [] = 0
somaAreas (x:xs) = area x + somaAreas xs

areaPoligonal :: Poligonal -> Double
areaPoligonal x = somaAreas (triangula x)

mover :: Poligonal -> Ponto -> Poligonal
mover [] _ = []
mover ((Ponto x1 y1):xs) (Ponto x2 y2) = moverAux (Ponto x1 y1:xs) (x2-x1,y2-y1)

moverAux :: Poligonal -> (Double,Double) -> Poligonal
moverAux [] _ = []
moverAux ((Ponto x y):xs) (dx,dy)= Ponto (x+dx) (y+dy):moverAux xs (dx,dy)

data Contacto = Casa Integer
                 | Trab Integer
                 | Tlm Integer
                 | Email String
    deriving Show
type Nome = String
type Agenda = [(Nome, [Contacto])]

acrescEmail :: Nome -> String -> Agenda -> Agenda
acrescEmail nome email a = a ++ [(nome, [Email email])]

verEmails :: Nome -> Agenda -> Maybe [String]
verEmails _ [] = Nothing
verEmails nome ((n, conts):xs)
    | nome == n = Just (extrairEmails conts)
    | otherwise = verEmails nome xs

extrairEmails :: [Contacto] -> [String]
extrairEmails [] = []
extrairEmails (Email em:xs) = em : extrairEmails xs
extrairEmails (_:xs) = extrairEmails xs

consTelefs :: [Contacto] -> [Integer]
consTelefs [] = []
consTelefs (Tlm tele:xs) = tele : consTelefs xs
consTelefs (Trab tele:xs) = tele : consTelefs xs
consTelefs (Casa tele:xs) = tele : consTelefs xs
consTelefs (_:xs) = consTelefs xs

casa :: Nome -> Agenda -> Maybe Integer
casa _ [] = Nothing
casa nome ((n, conts):xs)
    | nome == n = extrairCasa conts
    | otherwise = casa nome xs

extrairCasa :: [Contacto] -> Maybe Integer
extrairCasa [] = Nothing
extrairCasa (Casa casa:xs) = Just casa
extrairCasa (_:xs) = extrairCasa xs

type Dia = Int
type Mes = Int
type Ano = Int
data Data = D Dia Mes Ano
    deriving Show
type TabDN = [(Nome,Data)]

procura :: Nome -> TabDN -> Maybe Data
procura _ [] = Nothing
procura nIn ((nCur, d):xs)
    | nIn == nCur = Just d
    | otherwise = procura nIn xs

diferencaData :: Data -> Data -> Int
diferencaData (D d1 m1 a1) (D d2 m2 a2) =
    a2 - a1 -
        if (m2, d2) < (m1, d1) then 1 else 0

idade :: Data -> Nome -> TabDN -> Maybe Int
idade d nIn x = case procura nIn x of
    Nothing -> Nothing
    Just dN -> Just (diferencaData dN d)

anterior :: Data -> Data -> Bool
anterior d1 d2
    | diferencaData d2 d1 >= 0 = True
    | otherwise = False

ordenaAux :: (Nome,Data) -> TabDN -> TabDN
ordenaAux (n,d) [] = [(n,d)]
ordenaAux (n,d) ((n1, d1):xs)
    | diferencaData d d1 >= 0 = (n,d):(n1,d1):xs
    | otherwise = (n1,d1): ordenaAux (n,d) xs

ordena :: TabDN -> TabDN
ordena [] = []
ordena (x:xs) = ordenaAux x (ordena xs)

converteDataIdade:: Data -> TabDN -> [(Nome,Int)]
converteDataIdade d ((nome,nasc):xs) = (nome, diferencaData nasc d):converteDataIdade d xs

porIdade:: Data -> TabDN -> [(Nome,Int)]
porIdade _ [] = []
porIdade d x = converteDataIdade d (ordena x)

test2 = TestCase (assertEqual "for (foo 3)," "João" (fst (head (ordena [("João", D 10 5 2000), ("André", D 10 5 1990)]))))

tests = TestList [TestLabel "test2" test2]

data Movimento = Credito Float | Debito Float
        deriving Show
data Extracto = Ext Float [(Data, String, Movimento)]
        deriving Show

valorMov:: Movimento -> Float
valorMov (Credito v) = v
valorMov (Debito v) = v

extValor :: Extracto -> Float -> [Movimento]
extValor (Ext _ []) _ = []
extValor (Ext saldo((d, desc, m):xs)) min
    | valorMov m >= min = m:extValor (Ext saldo xs) min
    | otherwise = extValor (Ext saldo xs) min

filtroAux:: Extracto -> String -> [(Data, Movimento)]
filtroAux (Ext saldo ((d, desc, m):xs)) f
    | desc == f = (d, m):filtroAux (Ext saldo xs) f
    | otherwise = filtroAux (Ext saldo xs) f

filtro :: Extracto -> [String] -> [(Data,Movimento)]
filtro _ [] = []
filtro (Ext _ []) _ = []
filtro e (y:ys) = filtroAux e y ++ filtro e ys


creDeb :: Extracto -> (Float,Float)
creDeb (Ext _ []) = (0,0)
creDeb (Ext saldo ((_, _, Credito v):xs)) = (cred + v, deb)
    where
        (cred, deb) = creDeb (Ext saldo xs)
creDeb (Ext saldo ((_, _, Debito v):xs)) = (cred, deb + v)
    where
        (cred, deb) = creDeb (Ext saldo xs)

saldo :: Extracto -> Float
saldo (Ext s []) = s
saldo (Ext s ((_, _, Credito v):xs)) = saldo (Ext (s + v) xs)
saldo (Ext s ((_, _, Debito v):xs)) = saldo (Ext (s - v) xs)