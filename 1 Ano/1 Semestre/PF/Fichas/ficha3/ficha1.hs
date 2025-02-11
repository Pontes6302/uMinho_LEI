import Data.Char (ord)
import Data.Char (chr)

module ficha1.hs where
perimetroex1 :: Double -> Double
perimetroex1 r = 2 * pi * r

dist :: (Double,Double) -> (Double,Double) -> Double
dist (x1,y1) (x2,y2) = sqrt ((x1-x2)^2 + (y1-y2)^2)

primUlt :: [a] -> (a,a)
primUlt l = (head l,last l)

multiplo :: Int -> Int -> Bool
multiplo m n = m `mod` n == 0

truncaImpar :: [Int] -> [Int]
truncaImpar m = if length m `mod` 2 == 0 then m else tail m

max2 :: Int -> Int -> Int
max2 m n = if m > n then m else n

max3 :: Int -> Int -> Int -> Int
max3 m n s = max2 (max2 m n) s

nRaizes :: Double -> Double -> Double -> Int
nRaizes a b c
    | d > 0 = 2
    | d == 0 = 1
    | otherwise = 0
    where
        d = b^2-4*a*c

raizes :: Double -> Double -> Double -> [Double]
raizes a b c
    | nr == 2 = [(-b) + sqrt d/(2*a), -b - sqrt d/(2*a)]
    | nr == 1 = [(-b) / (2*a)]
    | otherwise = []
    where
        d = b^2-4*a*c
        nr = nRaizes a b c

horaValida :: (Int, Int) -> Bool
horaValida (h, m) = h >= 0 && h < 24 && m >= 0 && m < 60

horaMaisTardeQue :: (Int, Int) -> (Int, Int) -> Bool
horaMaisTardeQue (h1, m1) (h2, m2)
    | h1 > h2 = True
    | h1 == h2 && m1 > m2 = True
    | otherwise = False

horaParaMins :: (Int, Int) -> Int
horaParaMins (h, m) = h*60 + m

minsparaHoras :: Int -> (Int, Int)
minsparaHoras min = (div min 60, mod min 60)

horaDiferenca :: (Int,Int) -> (Int,Int) -> Int
horaDiferenca (h1,m1) (h2,m2) = a `max` b - a `min` b
        where
            a = horaParaMins (h1,m1)
            b = horaParaMins (h2,m2)

horaADDmins :: (Int,Int) -> Int ->(Int,Int)
horaADDmins (h,m) min = minsparaHoras (horaParaMins (h,m) + min)

data Hora = H Int Int deriving (Show,Eq)

horaDataA :: Hora -> Bool
horaDataA (H h m) = h >= 0 && h < 24 && m >= 0 && m < 60

horaDataB :: Hora -> Hora -> Bool
horaDataB (H h1 m1) (H h2 m2)
    | h1 > h2 = True
    | h1 == h2 && m1 > m2 = True
    | otherwise = False

horaDataC :: Hora -> Int
horaDataC (H h m) = h*60 + m

horaDataD :: Int -> Hora
horaDataD min = H (div min 60) (mod min 60)

horaDataE :: Hora -> Hora -> Int
horaDataE (H h1 m1) (H h2 m2) = a `max` b - a `min` b
        where
            a = horaDataC (H h1 m1)
            b = horaDataC (H h2 m2)

data Semaforo = Verde | Amarelo | Vermelho deriving (Show,Eq)

next :: Semaforo -> Semaforo
next Verde = Amarelo
next Amarelo = Vermelho
next Vermelho = Verde

stop :: Semaforo -> Bool
stop Verde = False
stop _ = True

safe :: Semaforo -> Semaforo -> Bool
safe Verde Verde = True
safe _ _ = False

data Ponto = Cartesiano Double Double | Polar Double Double deriving (Show,Eq)

posx :: Ponto -> Double
posx (Cartesiano x y) = x
posx (Polar r a) = sin a * r

posy :: Ponto -> Double
posy (Cartesiano x y) = y
posy (Polar r a) = cos a * r

raio :: Ponto -> Double
raio (Cartesiano x y) = sqrt (x^2 + y^2)
raio (Polar r a) = r

angulo :: Ponto -> Double
angulo (Cartesiano x y) = atan2 x y
angulo (Polar r a) = a

dist6 :: Ponto -> Ponto -> Double
dist6 (Cartesiano x1 y1) (Cartesiano x2 y2) = sqrt ((x1-x2)^2 + (y1-y2)^2)
dist6 (Cartesiano x1 y1) (Polar r a) =
    sqrt ((x1-posx (Polar r a))^2 + (y1-posy (Polar r a))^2)
dist6 (Polar r a) (Cartesiano x1 y1) =
    sqrt ((x1-posx (Polar r a))^2 + (y1-posy (Polar r a))^2)
dist6 (Polar r1 a1) (Polar r2 a2) = sqrt (r1^2 +r2^2 - (2*r1*r2*cos (a2-a1)))

data PontoXY = PontoXY Double Double deriving (Show,Eq)

data Figura =
    Circulo PontoXY Double |
    Retangulo PontoXY PontoXY |
    Triangulo PontoXY PontoXY PontoXY
    deriving (Show,Eq)

poligono :: Figura -> Bool
poligono (Circulo _ _) = False
poligono (Retangulo _ _) = True
poligono (Triangulo _ _ _) = True

vertices :: Figura -> [PontoXY]
vertices (Circulo _ _) = []
vertices (Retangulo (PontoXY x1 y1) (PontoXY x2 y2)) = 
    [PontoXY x1 y1, PontoXY x1 y2, PontoXY x2 y1, PontoXY x2 y2]
vertices (Triangulo a b c) = [a, b, c]

distPXY :: PontoXY -> PontoXY -> Double
distPXY (PontoXY x1 y1) (PontoXY x2 y2) = sqrt((x1 - x2)^2 + (y1-y2)^2)

area :: Figura -> Double
area (Triangulo p1 p2 p3) =
    let a = distPXY p1 p2
        b = distPXY p2 p3
        c = distPXY p3 p1
        s = (a+b+c) / 2 -- semi-perimetro
    in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron
area (Circulo (PontoXY x y) r) = pi * r
area (Retangulo (PontoXY x1 y1) (PontoXY x2 y2)) = abs (x1 - x2) * abs (y1 - y2)

perimetro :: Figura -> Double
perimetro (Circulo (PontoXY x y) r) = 2 * pi * r
perimetro (Retangulo (PontoXY x1 y1) (PontoXY x2 y2)) = (abs (x1 - x2) * 2) + (abs (y1 - y2) * 2)
perimetro (Triangulo p1 p2 p3) =
    distPXY p1 p2 + distPXY p2 p3 + distPXY p3 p1

isLower :: Char -> Bool
isLower a
    | ord a >= 97 && ord a <= 122 = True
    | otherwise = False

isDigit :: Char -> Bool
isDigit a
    | ord a >= 48 && ord a <= 57 = True
    | otherwise = False

isAlpha :: Char -> Bool
isAlpha a
    | ord a >= 97 && ord a <= 122 = True
    | ord a >= 65 && ord a <= 90 = True
    | otherwise = False

toUpper :: Char -> Char
toUpper a = chr(ord a - 32)

intToDigit :: Int -> Char
intToDigit a = chr(a + 48)

digitToInt :: Char -> Int
digitToInt a = ord a - 48