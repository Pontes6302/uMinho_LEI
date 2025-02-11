import Data.Char (ord)
import Data.List

data Frac = F Integer Integer

normaliza :: Frac -> Frac
normaliza (F n d) = F (n `div` m) (d `div` m)
    where 
        m = mdc n d
        mdc x y 
            | x == y = x
            | x > y = mdc (x-y) y
            | otherwise = mdc x (y-x)

instance Eq Frac where
    (F n1 d1) == (F n2 d2) = n1 * d2 == n2 * d1

instance Ord Frac where
    (F n1 d1) <= (F n2 d2) = n1 * d2 <= n2 * d1

instance Show Frac where
    show (F n d) = show n ++ "/" ++ show d

instance Num Frac where
    (F n1 d1) + (F n2 d2) = normaliza (F (n1*d2 + n2*d1) (d1*d2))
    (F n1 d1) - (F n2 d2) = normaliza (F (n1*d2 - n2*d1) (d1*d2))
    (F n1 d1) * (F n2 d2) = normaliza (F (n1*n2) (d1*d2))
    negate (F n d) = F (-n) d
    abs (F n d) = F (abs n) (abs d)
    signum (F n d) = F (signum n) 1
    fromInteger n = F n 1

maioresqueDobro :: Frac -> [Frac] -> [Frac]
maioresqueDobro f l = filter (> 2*f) l

data Exp a = Const a
    | Simetrico (Exp a)
    | Mais (Exp a) (Exp a)
    | Menos (Exp a) (Exp a)
    | Mult (Exp a) (Exp a)

instance Show a => Show (Exp a) where
    show (Const a) = show a
    show (Simetrico e) = "-(" ++ show e ++ ")"
    show (Mais e1 e2) = "(" ++ show e1 ++ "+" ++ show e2 ++ ")"
    show (Menos e1 e2) = "(" ++ show e1 ++ "-" ++ show e2 ++ ")"
    show (Mult e1 e2) = "(" ++ show e1 ++ "*" ++ show e2 ++ ")"

instance Eq a => Eq (Exp a) where
    (Const a) == (Const b) = a == b
    (Simetrico e1) == (Simetrico e2) = e1 == e2
    (Mais e1 e2) == (Mais e3 e4) = e1 == e3 && e2 == e4 || e1 == e4 && e2 == e3
    (Menos e1 e2) == (Menos e3 e4) = e1 == e3 && e2 == e4 || e1 == e4 && e2 == e3
    (Mult e1 e2) == (Mult e3 e4) = e1 == e3 && e2 == e4
    _ == _ = False

data Movimento = Credito Float | Debito Float deriving Show
data Data = D Int Int Int
data Extracto = Ext Float [(Data, String, Movimento)]

instance Show Data where
    show (D d m a) = show d ++ "/" ++ show m ++ "/" ++ show a

instance Eq Data where
    (D d1 m1 a1) == (D d2 m2 a2) = d1 == d2 && m1 == m2 && a1 == a2

instance Ord Data where
    (D d1 m1 a1) <= (D d2 m2 a2) = (a1,m1,d1) <= (a2,m2,d2)

ordena :: Extracto -> Extracto
ordena (Ext s l) = Ext s (sortOn (\(d,_,_) -> d) l)

instance Show Extracto where
    show (Ext s l) = "Saldo anterior: " ++ show s ++ "\n" ++ cabecalho ++ listaMov l ++ replicate 90 '-' 

listaMov :: [(Data, String, Movimento)] -> String
listaMov [] = ""
listaMov ((d,s,m):t) = preencheColuna (show d) 20 ++ preencheColuna s 30 ++ preencheColuna (show m) 20 ++ preencheColuna (show m) 20 ++ "\n" ++ listaMov t

preencheColuna :: String -> Int -> String
preencheColuna s n = s ++ replicate (n - length s) ' '

cabecalho = replicate 90 '-' ++ "\n" ++ preencheColuna "Data" 20
                                    ++ preencheColuna "Descricao" 30
                                    ++ preencheColuna "Credito" 20
                                    ++ preencheColuna "Debito" 20 ++ "\n"
                                    ++ replicate 90 '-' ++ "\n"

