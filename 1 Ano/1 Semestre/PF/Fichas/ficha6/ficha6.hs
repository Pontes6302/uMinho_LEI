data BTree a = Empty
    | Node a (BTree a) (BTree a)
        deriving Show

altura :: BTree a -> Int
altura Empty = 0
altura (Node _ e d) = 1 + max (altura e) (altura d)

contaNodos :: BTree a -> Int
contaNodos Empty = 0
contaNodos (Node _ e d) = 1 + contaNodos e + contaNodos d

folhas :: BTree a -> Int
folhas Empty = 1
folhas (Node _ e d) = folhas e + folhas d

prune :: Int -> BTree a -> BTree a
prune 0 _ = Empty
prune _ Empty = Empty
prune n (Node x e d) = Node x (prune (n-1) e) (prune (n-1) d)

path :: [Bool] -> BTree a -> [a]
path [] _ = []
path _ Empty = []
path (x:xs) (Node y e d)
    | x = y : path xs d 
    | otherwise = y : path xs e

mirror :: BTree a -> BTree a
mirror Empty = Empty
mirror (Node x e d) = Node x (mirror d) (mirror e)

zipWithBT :: (a -> b -> c) -> BTree a -> BTree b -> BTree c
ziopWithBT _ Empty _ = Empty
zipWithBT _ _ Empty = Empty
zipWithBT f (Node x e d) (Node y e' d') = Node (f x y) (zipWithBT f e e') (zipWithBT f d d')

unzipBT :: BTree (a,b,c) -> (BTree a,BTree b,BTree c)
unzipBT Empty = (Empty,Empty,Empty)
unzipBT (Node (x,y,z) e d) = (Node x e1 d1, Node y e2 d2, Node z e3 d3)
    where 
        (e1,e2,e3) = unzipBT e
        (d1,d2,d3) = unzipBT d

minimo :: Ord a => BTree a -> a
minimo (Node x Empty _) = x
minimo (Node x e _) = minimo e

semMinimo :: Ord a => BTree a -> BTree a
semMinimo (Node _ Empty d) = d
semMinimo (Node x e d) = Node x (semMinimo e) d

minSmin :: Ord a => BTree a -> (a,BTree a)
minSmin (Node x Empty d) = (x,d)
minSmin (Node x e d) = (y,Node x e' d)
    where
        (y,e') = minSmin e

instance Eq a => Eq (BTree a) where
    Empty == Empty = True
    (Node x1 l1 r1) == (Node x2 l2 r2) = x1 == x2 && l1 == l2 && r1 == r2
    _ == _ = False

remove :: Ord a => a -> BTree a -> BTree a
remove _ Empty = Empty
remove x (Node y e d)
    | x < y = Node y (remove x e) d
    | x > y = Node y e (remove x d)
    | otherwise = 
        if e == Empty then d
        else if d == Empty then e
        else Node minRight e newRight
            where
                (minRight,newRight) = minSmin d

type Aluno = (Numero,Nome,Regime,Classificacao)
type Numero = Int
type Nome = String
data Regime = ORD | TE | MEL deriving Show
data Classificacao = Aprov Int
    | Rep
    | Faltou
    deriving Show
type Turma = BTree Aluno -- arvore binaria de procura (ordenada por numero)

inscNum :: Numero -> Turma -> Bool
inscNum _ Empty = False
inscNum n (Node (x,_,_,_) e d)
    | n == x = True
    | n < x = inscNum n e
    | otherwise = inscNum n d

inscNome :: Nome -> Turma -> Bool
inscNome _ Empty = False
inscNome n (Node (_,x,_,_) e d)
    | n == x = True
    | otherwise = inscNome n e || inscNome n d

trabEst :: Turma -> [(Numero,Nome)]
trabEst Empty = []
trabEst (Node (n,x,TE,_) e d) = (n,x) : trabEst e ++ trabEst d

nota :: Numero -> Turma -> Maybe Classificacao
nota _ Empty = Nothing
nota n (Node (x,_,_,c) e d)
    | n == x = Just c
    | n < x = nota n e
    | otherwise = nota n d

percFaltas :: Turma -> Float
percFaltas Empty = 0
percFaltas t = (fromIntegral faltas / fromIntegral total) * 100
    where
        faltas = contaFaltas t
        total = contaAlunos t
        contaFaltas Empty = 0
        contaFaltas (Node (_,_,_,Faltou) e d) = 1 + contaFaltas e + contaFaltas d
        contaAlunos Empty = 0
        contaAlunos (Node _ e d) = 1 + contaAlunos e + contaAlunos d

mediaAprov :: Turma -> Float
mediaAprov Empty = 0
mediaAprov t = fromIntegral soma / fromIntegral total
    where
        (soma,total) = somaAprov t
        somaAprov Empty = (0,0)
        somaAprov (Node (_,_,_,Aprov x) e d) = (x + s1 + s2,1 + t1 + t2)
            where
                (s1,t1) = somaAprov e
                (s2,t2) = somaAprov d

aprovAv :: Turma -> Float
aprovAv Empty = 0
aprovAv t = fromIntegral aprov / fromIntegral total
    where
        (aprov,total) = aprovados t
        aprovados :: Turma -> (Int,Int)
        aprovados Empty = (0,0)
        aprovados (Node (_,_,_,Aprov _) e d) = (1 + a1 + a2,1 + t1 + t2)
            where
                (a1,t1) = aprovados e
                (a2,t2) = aprovados d
        aprovados (Node (_,_,_,Faltou) e d) = (a1 + a2,1 + t1 + t2)
            where
                (a1,t1) = aprovados e
                (a2,t2) = aprovados d
        aprovados (Node (_,_,_,Rep) e d) = (a1 + a2,1 + t1 + t2)
            where
                (a1,t1) = aprovados e
                (a2,t2) = aprovados d
        