CREATE TABLE M1 (
    K int NOT NULL IDENTITY(1, 1),
    V varchar(20),
    PRIMARY KEY (K)
);

CREATE TABLE S1 (
    K int NOT NULL IDENTITY(1, 1),
	MKF int,
    V varchar(20),
    PRIMARY KEY (K),
	FOREIGN KEY (MKF) REFERENCES M1(K)
);

CREATE TABLE M2 (
    K1 int NOT NULL,
	K2 int NOT NULL,
    V varchar(20),
    PRIMARY KEY (K1,K2)
);

CREATE TABLE S2 (
    K int NOT NULL IDENTITY(1, 1),
	MK1F int,
	MK2F int,
    V varchar(20),
    PRIMARY KEY (K),
	FOREIGN KEY (MK1F, MK2F) REFERENCES M2(K1 ,K2)
	ON UPDATE CASCADE
	ON DELETE CASCADE
);

INSERT INTO M2(K1,K2,V)
VALUES (1,1,'a'),(2,2,'a'),(3,3,'a')

INSERT INTO S2(MK1F,MK2F,V)
VALUES (1,1,'a'),(2,2,'a'),(3,3,'a') --,(4,4,'a')

UPDATE M2
SET K2 = 1, K1 = 1
WHERE K2 = 4 AND K1 = 4

DELETE FROM M2 WHERE K2 = 1 AND K1 = 1