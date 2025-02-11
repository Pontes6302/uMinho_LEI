alterna :: Num a => Int -> a -> [a]
alterna 0 _ = []
alterna n x = x : alterna (n-1) (-x)

data Turma = Empty | Node (Integer, String) Turma Turma

instance Show Turma where
    show Empty = ""
    show (Node (n,s) e d) = show n ++ " " ++ s ++ "\n" ++ show e ++ show d

limites :: Turma -> (Integer, Integer)
limites t = (auxmin t, auxmax t)
    where
        auxmin Empty = 0
        auxmin (Node (n,s) Empty _) = n
        auxmin (Node (_,_) e _) = auxmin e
        auxmax Empty = 0
        auxmax (Node (n,s) _ Empty) = n
        auxmax (Node (_,_) _ d) = auxmax d

type TabAbrev = [(Palavra, Abreviatura)]
type Palavra = String
type Abreviatura = String

diffMaior :: TabAbrev -> (Palavra,Int)
diffMaior [] = ("",0)
diffMaior ((p,a):xs)
    | diff > snd (diffMaior xs) = (p,diff)
    | otherwise = diffMaior xs
    where
        diff = length p - length a

subs:: [String] -> TabAbrev -> [String]
subs [] _ = []
subs _ [] = []
subs (x:xs) t = aux x t : subs xs t
    where
        aux x [] = x
        aux x ((p,a):xs)
            | x == a = p
            | otherwise = aux x xs

data LTree a = Tip a | Fork (LTree a) (LTree a)

dumpLT :: LTree a -> [(a,Int)]
dumpLT t = aux t 0
    where
        aux (Tip a) n = [(a,n)]
        aux (Fork e d) n = aux e (n+1) ++ aux d (n+1)

undumpLT :: [(a,Int)] -> LTree a
undumpLT [] = error "Lista vazia"
undumpLT [(a,0)] = Tip a
undumpLT l = Fork (aux l 1) (aux l 1)
    where
        aux ((a,n):xs) i
            | n == i = Tip a
            | otherwise = Fork (aux xs (i+1)) (aux xs (i+1))