import System.Random (RandomGen(split))
data ExpInt = Const Int
            | Simetrico ExpInt
            | Mais ExpInt ExpInt
            | Menos ExpInt ExpInt
            | Mult ExpInt ExpInt

calcula :: ExpInt -> Int
calcula (Const x) = x
calcula (Simetrico x) = - calcula x
calcula (Mais x y) = calcula x + calcula y
calcula (Menos x y) = calcula x - calcula y
calcula (Mult x y) = calcula x * calcula y

infixa :: ExpInt -> String
infixa (Const x) = show x
infixa (Simetrico x) = "-(" ++ infixa x ++ ")"
infixa (Mais x y) = "(" ++ infixa x ++ "+" ++ infixa y ++ ")"
infixa (Menos x y) = "(" ++ infixa x ++ "-" ++ infixa y ++ ")"
infixa (Mult x y) = "(" ++ infixa x ++ "*" ++ infixa y ++ ")"

posfixa :: ExpInt -> String
posfixa (Const x) = show x
posfixa (Simetrico x) = posfixa x ++ " -"
posfixa (Mais x y) = posfixa x ++ " " ++ posfixa y ++ " +"
posfixa (Menos x y) = posfixa x ++ " " ++ posfixa y ++ " -"
posfixa (Mult x y) = posfixa x ++ " " ++ posfixa y ++ " *"

data RTree a = R a [RTree a]

soma :: Num a => RTree a -> a
soma (R x []) = x
soma (R x l) = x + sum (map soma l)

altura :: RTree a -> Int
altura (R _ []) = 1
altura (R _ l) = 1 + maximum (map altura l)

prune :: Int -> RTree a -> RTree a
prune 1 (R x _) = R x []
prune n (R x l) = R x (map (prune (n-1)) l)

mirror :: RTree a -> RTree a
mirror (R x l) = R x (reverse (map mirror l))

postorder :: RTree a -> [a]
postorder (R x []) = [x]
postorder (R x l) = concatMap postorder l ++ [x]

data BTree a = Empty | Node a (BTree a) (BTree a)
data LTree a = Tip a | Fork (LTree a) (LTree a)

ltSum :: Num a => LTree a -> a
ltSum (Tip x) = x
ltSum (Fork e d) = ltSum e + ltSum d

listaLT :: LTree a -> [a]
listaLT (Tip x) = [x]
listaLt (Fork e d) = listaLT e ++ listaLT d

ltHeight :: LTree a -> Int
ltHeight (Tip _) = 1
ltHeight (Fork e d) = 1 + max (ltHeight e) (ltHeight d)

data FTree a b = Leaf b | No a (FTree a b) (FTree a b)

splitFTree :: FTree a b -> (BTree a, LTree b)
splitFTree (Leaf x) = (Empty, Tip x)
splitFTree (No x e d) = (Node x e1 d1, Fork l1 l2)
    where
        (e1,l1) = splitFTree e
        (d1,l2) = splitFTree d

joinTrees :: BTree a -> LTree b -> Maybe (FTree a b)
joinTrees Empty (Tip x) = Just (Leaf x)
joinTrees (Node x e d) (Fork l1 l2) = case (joinTrees e l1, joinTrees d l2) of
    (Just e1, Just d1) -> Just (No x e1 d1)
    _ -> Nothing