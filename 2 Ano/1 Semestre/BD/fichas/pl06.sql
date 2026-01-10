CREATE TABLE Família (
Id INT NOT NULL,
Designação VARCHAR(75),

PRIMARY KEY (Id)
);

CREATE TABLE Operações(
Id INT NOT NULL,
Designação VARCHAR(75),
CustoHora DECIMAL(8,2),

Primary Key (Id)
);

CREATE TABLE Peças(
Id INT NOT NULL,
Designação VARCHAR(100) NOT NULL,
Família INT,

PRIMARY KEY (Id),
FOREIGN KEY (Família)
	REFERENCES Família(Id)
);

CREATE TABLE Técnicos (
Id INT NOT NULL,
Nome VARCHAR(75),
Função VARCHAR(100) NOT NULL,
CurriculumVtae TEXT,
Responsável INT NOT NULL,
Técnicos_Id1 INT,

PRIMARY KEY (Id),
FOREIGN KEY (Técnicos_Id1)
	REFERENCES Técnicos(Id)
);

CREATE TABLE TécnicosOperações(
Técnico INT NOT NULL,
Operação INT NOT NULL,

PRIMARY KEY (Técnico, Operação),
FOREIGN KEY (Técnico)
	REFERENCES Técnicos(Id),
FOREIGN KEY (Operação)
	REFERENCES Operações(Id)
);

CREATE TABLE Aparelhos(
Id INT NOT NULL,
Designação VARCHAR(100) NOT NULL,
Referência VARCHAR(25),
PreçoVenda DECIMAL(10,2) NOT NULL,
PreçoProdução DECIMAL(10,2) NOT NULL,
NrPeças INT,
NrOperações INT,
Observações TEXT,

PRIMARY KEY (Id)
);

CREATE TABLE Produção(
NrOrdemFabrico INT NOT NULL,
Aparelho INT NOT NULL,
Quantidade INT NOT NULL,
InícioProdução DATETIME NOT NULL,
FimProdução DATETIME,
EntradaStock DATETIME,
JornalProdução TEXT,

PRIMARY KEY (NrOrdemFabrico),
FOREIGN KEY (Aparelho)
	REFERENCES Aparelhos(Id)
);

CREATE TABLE Montagem(
Aparelho INT NOT NULL,
Peça INT NOT NULL,
Operação INT NOT NULL,
Quantidade INT NOT NULL,
Custo DECIMAL(8,2) NOT NULL,

PRIMARY KEY (Aparelho, Peça, Operação),
FOREIGN KEY (Aparelho)
	REFERENCES Aparelhos(Id),
FOREIGN KEY (Peça)
	REFERENCES Peças(Id),
FOREIGN KEY (Operação)
	REFERENCES Operações(Id)
);

CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin123';
CREATE USER 'consult'@'localhost' IDENTIFIED BY 'consult123';

GRANT ALL PRIVILEGES ON pl06.* TO 'admin'@'localhost';
GRANT SELECT ON pl06.* TO 'consult'@'localhost';

CREATE INDEX idx_peçasdesignação ON Peças(Designação);
CREATE INDEX idx_aparelhosdesignação ON Aparelhos(Designação);
CREATE INDEX idx_operaçõesdesignação ON Operações(Designação);
CREATE INDEX idx_função ON Técnicos(Função);

INSERT INTO Família(Id, Designação) 
	VALUES (1, 'Elétrica'), (2, 'Mecânica');
INSERT INTO Peças(Id, Designação, Família) 
	VALUES (1, 'Motor 220v', 2), (2, 'Bobina', 1);

INSERT INTO Técnicos(Id, Nome, Função, Responsável) 
	VALUES (1, 'André', 'Trolha', 1), (2, 'Pedro', 'Eletrecista', 1);
INSERT INTO Operações(Id, Designação, CustoHora) 
	VALUES (1, 'RádioNov', 2300.5), (2, 'AspiradorNov', 329.9);
INSERT INTO Aparelhos(Id, Designação, PreçoVenda, PreçoProdução)
	VALUES (1, 'Rádio', 300.0, 152.75), (2, 'Aspirador', 399.9, 120.23);

SELECT Designação FROM Peças;