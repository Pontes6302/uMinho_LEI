{-|
Module      : Ficha5
Description : Módulo Haskell contendo ficha 5 de PF.
Copyright   : (c) Sívio <a100762@uminho.pt>, 2024
Stability   : experimental
Portability : POSIX

Funções de ordem superior.
-}

any' :: (a -> Bool) -> [a] -> Bool
any' _ [] = False
any' p (x:xs) = p x || any' p xs

zipWith' :: (a->b->c) -> [a] -> [b] -> [c]
zipWith' _ _ [] = []
zipWith' _ [] _ = []
zipWith' p (x:xs) (y:ys) = p x y:zipWith' p xs ys

takeWhile' :: (a->Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' p (x:xs)
    | not (p x) = []
    | otherwise = x:takeWhile' p xs

dropWhile' :: (a->Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' p (x:xs)
    | p x = dropWhile' p xs
    | otherwise = x:xs

span' :: (a-> Bool) -> [a] -> ([a],[a])
span' _ [] = ([],[])
span' p (x:xs)
    | p x = (x:a,b)
    | otherwise = ([],x:xs)
    where
        (a,b) = span' p xs

deleteBy' :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteBy' _ _ [] = []
deleteBy' p n (x:xs)
    | p n x = xs
    | otherwise = x:deleteBy' p n xs

sortOn' :: Ord b => (a -> b) -> [a] -> [a]
sortOn' _ [] = []
sortOn' f (x:xs) = insere x (sortOn' f xs)
    where
        insere x [] = [x]
        insere x (y:ys)
            | f x < f y = x:y:ys
            | otherwise = y : insere x ys

type Polinomio = [Monomio]
type Monomio = (Float,Int)

selgrau :: Int -> Polinomio -> Polinomio
selgrau _ [] = []
selgrau g p = filter (\(c,e) -> e==g) p

--conta :: Int -> Polinomio -> Int
--conta 

grau :: Polinomio -> Int
grau [] = 0
grau x = maximum (map snd x)

deriv :: Polinomio -> Polinomio
deriv [] = []
deriv p = map (\(c,e) -> (fromIntegral e*c, e-1)) (filter (\(c,e) -> e/=0) p)

calcula :: Float -> Polinomio -> Float
calcula _ [] = 0
calcula x p = sum (map (\(c,e) -> (c*x)^e) p)

calcula2 :: Float -> Polinomio -> Float
calcula2 _ [] = 0
calcula2 v p = foldr (\(c,e) s -> c*(v^e) + s) 0 p

simp :: Polinomio -> Polinomio
simp [] = []
simp p = filter (\(c,e) -> c/=0) p

--mult :: Monomio -> Polinomio -> Polinomio
--mult _ [] = []

ordena :: Polinomio -> Polinomio
ordena = sortOn' snd

normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza p = (sum (map fst x), e): normaliza y
    where
        po@((c,e):t) = ordena p
        (x,y) = span' (\(c1,e1) -> e1 == e) po

type Mat a = [[a]]

dimOK :: Mat a -> Bool
dimOK (m:ms) = all ((== length m) . length) ms

dimMat :: Mat a -> (Int,Int)
dimMat m = (length m, length (head m))

addMat :: Num a => Mat a -> Mat a -> Mat a
addMat [] [] = []
addMat (m1:m1s) (m2:m2s) = zipWith' (+) m1 m2 : addMat m1s m2s

addMat2 :: Num a => Mat a -> Mat a -> Mat a
addMat2 = zipWith (zipWith (+))

transpose :: Mat a -> Mat a
transpose [] = []
transpose ([] : _) = []
transpose m = map head m : transpose (map tail m)