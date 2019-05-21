
---------------- Laboratório SQL: Retorne os comandos em SQL do laboratório.  
---------------- Data do laboratório: 23 de maio de 2017

-- 1 e 2. Criação das tabelas
CREATE TABLE Instrutor ( 
    InstrutorID   	INT   			NOT NULL,
    CPF				INT				NOT NULL  UNIQUE,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Endereco   		VARCHAR( 60 ),
    CONSTRAINT InstrutorPK PRIMARY KEY (InstrutorID) 
);

CREATE TABLE Aluno ( 
    AlunoID   		INT   			NOT NULL,
    CPF				INT				NOT NULL  UNIQUE,
    Nome  			VARCHAR( 60 )  	NOT NULL,
    Endereco   		VARCHAR( 60 ),
    CONSTRAINT AlunoPK PRIMARY KEY (AlunoID) 
);

CREATE TABLE Escola ( 
    EscolaID   		INT   			NOT NULL,
    CNPJ			INT				NOT NULL  UNIQUE,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Endereco   		VARCHAR( 60 ),
    CONSTRAINT EscolaPK PRIMARY KEY (EscolaID) 
);

CREATE TABLE Curso ( 
    CursoID   		INT   			NOT NULL,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Carga_horaria	INT 			NOT NULL,
    Ementa			VARCHAR( 500 )	,
    EscolaID        INT 			NOT NULL,
    
    CONSTRAINT CursoPK PRIMARY KEY (CursoID), 
    
    CONSTRAINT CursoEscolaFK 	FOREIGN KEY (EscolaID) 
    							REFERENCES Escola(EscolaID) 
    							ON DELETE CASCADE 
    							ON UPDATE CASCADE
);

--Tabela Curso
CREATE TABLE Turma (
  TurmaID INT NOT NULL,
  Data_inicio DATE NOT NULL,
  Data_termino DATE NOT NULL,
  CursoID INT NOT NULL,
  InstrutorID INT NOT NULL,

  CONSTRAINT TurmaPK PRIMARY KEY (TurmaID),

  CONSTRAINT TurmaCursoFK FOREIGN KEY (CursoID)
                   REFERENCES curso(cursoid)
                   ON DELETE CASCADE
                   ON UPDATE CASCADE,

  CONSTRAINT TurmaInstrutorFK FOREIGN KEY (InstrutorID)
                   REFERENCES instrutor(instrutorid)
                   ON DELETE CASCADE
                   ON UPDATE CASCADE
);

CREATE TABLE Matricula (
  TurmaID INT NOT NULL,
  AlunoID INT NOT NULL,
  Nota_final NUMERIC(4, 2),
  presenca INT NOT NULL,

  CONSTRAINT MatriculaTurmaAlunoPK PRIMARY KEY (TurmaID, AlunoID),


  CONSTRAINT MatriculaTurmaFK FOREIGN KEY (TurmaID)
                   REFERENCES turma(turmaid)
                   ON DELETE CASCADE
                   ON UPDATE CASCADE,

  CONSTRAINT MatriculaAlunoFK FOREIGN KEY (AlunoID)
                   REFERENCES aluno(alunoid)
                   ON DELETE CASCADE
                   ON UPDATE CASCADE
);

ALTER TABLE Aluno ALTER COLUMN nome TYPE varchar(100);

-- 3. Use os comandos SQL para inserir dados na tabela Instrutor 

INSERT INTO Instrutor VALUES(1, 11111, 'Rodrigo Carvalho', 'Rua Alfa, num 50, Centro');
INSERT INTO Instrutor VALUES(2, 22222, 'Jacqueline França', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Instrutor VALUES(3, 33333, 'Leandro Siqueira', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Instrutor VALUES(4, 44444, 'Diego Faria', 'Rua Siqueira Campos, num 80, Jd Apolo');


-- 4. Use os comandos SQL para inserir dados na tabela Aluno
INSERT INTO Aluno VALUES(1, 12222, 'Jose Vitor Ferreira Fernandes Gomes Dias', 'Rua Alfa, num 100, Centro');
INSERT INTO Aluno VALUES(2, 32222, 'Rodrigo Gomes Dias', 'Rua Sete de Setembro, num 200, Alvorada');
INSERT INTO Aluno VALUES(3, 42222, 'Daniel Ribeiro Alvarenga', 'Rua Nelson Davila, num 150, Centro');
INSERT INTO Aluno VALUES(4, 52222, 'Gustavo Ferreira', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(5, 62222, 'Marcelo Reis Fernandes', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(6, 72222, 'Renata Fernandes Carvalho', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(7, 82222, 'Debora Ribeiro Reis', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(8, 92222, 'Daniela Reis Barbosa', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Aluno VALUES(9, 13333, 'Luciane Cardoso', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(10, 91919, 'Claudio Cardoso', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(11, 81818, 'Marina Reis Alvarenga', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(12, 71717, 'Sabrina Carvalho', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Aluno VALUES(13, 61616, 'Julio Cesar Dias', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(14, 51515, 'Regiane Limeira', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(15, 41414, 'Augusto Dias Gomes', 'Rua Nelson Davila, num 120, Centro');

-- OBS: Erro ao inserir o primeiro registro, temos que aumentar o range do atributo nome


-- 5. Use os comandos SQL para inserir dados na tabela Escola, Curso, Turma e Matricula

INSERT INTO Escola VALUES(1, 11111, 'InfoSys', 'Rua Nelson Davila, num 400, Centro');
INSERT INTO Escola VALUES(2, 22222, 'Inova', 'Rua Sete de Setembro, num 800, Alvorada');
INSERT INTO Escola VALUES(3, 33333, 'CodSys', 'Rua Alfa, num 1030, Apolo');

INSERT INTO Curso VALUES(1, 'Linux - Introduction', 120, '', 1);
INSERT INTO Curso VALUES(2, 'Linux - Advanced', 120, '', 1);
INSERT INTO Curso VALUES(3, 'Windows - Introduction', 120, '', 1);
INSERT INTO Curso VALUES(4, 'Windows - Advanced', 120, '', 1);
INSERT INTO Curso VALUES(5, 'C++ Programming Language', 240, '', 3);
INSERT INTO Curso VALUES(6, 'Java Programming Language', 240, '', 3);
INSERT INTO Curso VALUES(7, 'Python', 120, '', 3);
INSERT INTO Curso VALUES(8, 'Database System and SQL', 240, '', 2);
INSERT INTO Curso VALUES(9, 'Data Science', 240, '', 2);
INSERT INTO Curso VALUES(10, 'Geoinformatics', 240, '', 2);

INSERT INTO Turma VALUES(1, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-06-15', 'YYYY-MM-DD'), 1, 1);
INSERT INTO Turma VALUES(2, to_date('2015-08-15', 'YYYY-MM-DD'), to_date('2015-12-15', 'YYYY-MM-DD'), 2, 1);
INSERT INTO Turma VALUES(3, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-06-15', 'YYYY-MM-DD'), 1, 1);
INSERT INTO Turma VALUES(4, to_date('2016-08-15', 'YYYY-MM-DD'), to_date('2016-12-15', 'YYYY-MM-DD'), 2, 1);
INSERT INTO Turma VALUES(5, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-06-15', 'YYYY-MM-DD'), 3, 2);
INSERT INTO Turma VALUES(6, to_date('2015-08-15', 'YYYY-MM-DD'), to_date('2015-12-15', 'YYYY-MM-DD'), 4, 2);
INSERT INTO Turma VALUES(7, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-06-15', 'YYYY-MM-DD'), 3, 2);
INSERT INTO Turma VALUES(8, to_date('2016-08-15', 'YYYY-MM-DD'), to_date('2016-12-15', 'YYYY-MM-DD'), 4, 2);
INSERT INTO Turma VALUES(9, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-06-15', 'YYYY-MM-DD'), 7, 3);
INSERT INTO Turma VALUES(10, to_date('2016-08-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 7, 3);
INSERT INTO Turma VALUES(11, to_date('2017-02-15', 'YYYY-MM-DD'), to_date('2017-06-15', 'YYYY-MM-DD'), 7, 3);
INSERT INTO Turma VALUES(12, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 5, 4);
INSERT INTO Turma VALUES(13, to_date('2017-02-15', 'YYYY-MM-DD'), to_date('2017-11-15', 'YYYY-MM-DD'), 5, 4);
INSERT INTO Turma VALUES(14, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 6, 3);
INSERT INTO Turma VALUES(15, to_date('2017-02-15', 'YYYY-MM-DD'), to_date('2017-11-15', 'YYYY-MM-DD'), 6, 3);
INSERT INTO Turma VALUES(16, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-11-15', 'YYYY-MM-DD'), 8, 1);
INSERT INTO Turma VALUES(17, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 8, 1);
INSERT INTO Turma VALUES(18, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-11-15', 'YYYY-MM-DD'), 10, 4);
INSERT INTO Turma VALUES(19, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 10, 4);

-- TurmaID, AlunoID, Nota e Presenca
INSERT INTO Matricula VALUES(1, 1, '8.4', 80);   
INSERT INTO Matricula VALUES(1, 2, '6.4', 85);   
INSERT INTO Matricula VALUES(1, 3, '5.0', 67);   
INSERT INTO Matricula VALUES(1, 4, '9.4', 100);   
INSERT INTO Matricula VALUES(1, 5, '8.7', 100); 
  
INSERT INTO Matricula VALUES(2, 1, '7.4', 80);   
INSERT INTO Matricula VALUES(2, 2, '7.4', 85);   
INSERT INTO Matricula VALUES(2, 3, '8.0', 80);   
INSERT INTO Matricula VALUES(2, 4, '7.4', 70);   
INSERT INTO Matricula VALUES(2, 5, '9.7', 100);   

INSERT INTO Matricula VALUES(3, 6, '8.4', 80);   
INSERT INTO Matricula VALUES(3, 7, '6.4', 85);   
INSERT INTO Matricula VALUES(3, 8, '5.0', 67);   
INSERT INTO Matricula VALUES(3, 9, '9.4', 100);   
INSERT INTO Matricula VALUES(3, 10, '8.7', 100); 
  
INSERT INTO Matricula VALUES(4, 6, '7.4', 80);   
INSERT INTO Matricula VALUES(4, 7, '9.4', 85);   
INSERT INTO Matricula VALUES(4, 8, '8.0', 80);   
INSERT INTO Matricula VALUES(4, 9, '7.4', 70);   
INSERT INTO Matricula VALUES(4, 10, '9.7', 100); 

INSERT INTO Matricula VALUES(9, 11, '7.4', 80);   
INSERT INTO Matricula VALUES(9, 12, '9.4', 85);   
INSERT INTO Matricula VALUES(9, 13, '8.0', 70);  

INSERT INTO Matricula VALUES(10, 14, '7.4', 80);   
INSERT INTO Matricula VALUES(10, 15, '9.4', 85);   
INSERT INTO Matricula VALUES(10, 1, '8.0', 70);  

INSERT INTO Matricula VALUES(11, 2, '7.4', 80);   
INSERT INTO Matricula VALUES(11, 3, '9.4', 85);   
INSERT INTO Matricula VALUES(11, 4, '8.0', 70);  


-- 6. A) Quais esquemas existem nesse banco de dados?
SELECT DISTINCT table_schema FROM information_schema.tables;

-- 6. B) Recupere as informações sobre as tabelas do esquema “public“.
SELECT DISTINCT * FROM information_schema.tables WHERE table_schema = 'public';

-- 6. C) Recupere as informações sobre todas as colunas de todas as tabelas do esquema “public”.
SELECT * FROM information_schema.columns WHERE table_schema = 'public';

-- Recupere as informações sobre todas as restrições (constraints) de todas as tabelas do esquema “public”.
SELECT DISTINCT 
    tc.constraint_schema, tc.table_name, tc.table_name, tc.constraint_type,
    tc.constraint_name
FROM
    information_schema.table_constraints AS tc
    JOIN information_schema.key_column_usage AS kcu
      ON tc.constraint_name = kcu.constraint_name
    JOIN information_schema.constraint_column_usage AS ccu
      ON ccu.constraint_name = tc.constraint_name

-- 7 Selecione todos alunos ordenados pelo nome.
SELECT * FROM aluno ORDER BY nome;

-- 8 Quantos cursos estão cadastrados no banco de dados?
SELECT COUNT(cursoid) AS quantidade_curso FROM curso;


--9 Quantos cursos foram ministrados pelo instrutor 'Leandro Siqueira'?
SELECT COUNT(i.nome) as quantidade_cursos
FROM turma AS t
  JOIN instrutor AS i
  ON t.instrutorid = i.instrutorid
WHERE i.nome = 'Leandro Siqueira';


-- 10 Quantas horas de curso foram ministradas pelo instrutor 'Leandro Siqueira'?
SELECT SUM(c.carga_horaria) AS total_horas
FROM turma AS t
  JOIN instrutor AS i
  ON t.instrutorid = i.instrutorid
  JOIN curso AS c on t.cursoid = c.cursoid
WHERE i.nome = 'Leandro Siqueira';

-- 11 Quantas turmas foram ministradas por cada instrutor?
SELECT i.nome AS instrutor, COUNT(t.turmaid) AS total_turmas
FROM turma AS t
  JOIN instrutor AS i
  ON t.instrutorid = i.instrutorid
GROUP BY i.nome;

-- 12 Quantas horas de curso foram ministradas por cada instrutor ?
SELECT i.nome AS instrutor, sum(c.carga_horaria) AS total_horas
FROM turma AS t
  JOIN instrutor AS i
  ON t.instrutorid = i.instrutorid
JOIN curso AS c ON t.cursoid = c.cursoid
GROUP BY i.nome;

-- 13 Se os cursos pagam 100,00 por hora ministrada, quanto cada instrutor recebeu por ano?
SELECT i.nome AS instrutor, (extract(year FROM t.data_inicio)), (sum(c.carga_horaria)*100) AS ganho_total_ano
FROM turma AS t
  JOIN instrutor AS i ON t.instrutorid = i.instrutorid
  JOIN curso AS c ON t.cursoid = c.cursoid
GROUP BY i.instrutorid, t.data_inicio
ORDER BY i.nome;

-- 14 Quais instrutores deram mais que 850 horas de curso?
SELECT i.nome AS instrutor, sum(c.carga_horaria) AS total_horas
FROM turma AS t
  JOIN instrutor AS i
  ON t.instrutorid = i.instrutorid
  JOIN curso AS c ON t.cursoid = c.cursoid
GROUP BY i.nome
HAVING SUM(c.carga_horaria) > 850;

-- 15 Quantas turmas cada curso teve por ano?
SELECT DISTINCT c.nome, COUNT(t.turmaid) AS quantidade_turmas
FROM curso as c
  JOIN turma t on c.cursoid = t.cursoid
GROUP BY c.nome;

-- 16 Quais cursos o aluno 'Rodrigo Gomes Dias' cursou e qual foi a nota dele em cada um?
SELECT DISTINCT a.nome as nome_aluno, c.nome AS nome_curso, m.nota_final as nota_final
FROM aluno AS a
  JOIN matricula AS m on a.alunoid = m.alunoid
  JOIN turma AS t on m.turmaid = t.turmaid
  JOIN curso AS c on t.cursoid = c.cursoid
WHERE a.nome = 'Rodrigo Gomes Dias';

-- 17 Crie uma view que contenha o histórico dos alunos contendo as seguintes 
-- informações: nome do aluno, CPF do aluno, endereço do aluno, curso ministrado, 
-- data de inicio e termino do curso, nome do instrutor do curso, carga horaria, 
-- nota final, presença
CREATE OR REPLACE VIEW view_historico_alunos AS
  SELECT DISTINCT
		a.nome as aluno, 
		a.cpf, a.endereco, 
		c.nome, 
		t.data_inicio, 
		t.data_termino, 
		i.nome AS instrutor,
		c.carga_horaria, 
		m.nota_final, 
		m.presenca
	FROM aluno AS a
    JOIN matricula AS m on a.alunoid = m.alunoid
    JOIN turma AS t on m.turmaid = t.turmaid
    JOIN curso AS c on t.cursoid = c.cursoid
    JOIN instrutor AS i on t.instrutorid = i.instrutorid
ORDER BY a.nome;

-- 18 Insira uma nova turma na tabela Turma
INSERT INTO turma
  (turmaid, instrutorid, cursoid, data_inicio, data_termino)
VALUES (21, 2, 1, '20-05-2019', '20-06-2019');

-- 19 Altere o nome do instrutor "Diego Faria" para "Diego Garcia Faria"
UPDATE instrutor
  SET nome = 'Diego Garcia Faria'
WHERE nome = 'Diego Faria';

-- 20 Aumente a nota de todos alunos em 10%
UPDATE matricula
  SET nota_final = nota_final+(nota_final*0.1)
;

-- 21 Remova o instrutor "Rodrigo Carvalho" da tabela instrutor. 
-- OBS: Observe o que acontece com as turmas associadas ao instrutor 
-- "Rodrigo Carvalho". --Todas as turmas em que o instrutor dava aula, também foram removidas
DELETE FROM instrutor
WHERE nome = 'Rodrigo Carvalho';

-- 22 Mude o atributo "CNPJ" da tabela "Escola" para um tipo textual.
ALTER TABLE escola
ALTER COLUMN cnpj TYPE VARCHAR(16);

-- 23 Renomeie o atributo "CNPJ" para "CNPJ_Escola".
ALTER TABLE escola
RENAME COLUMN cnpj TO CNPJ_Escola;

-- 24 Remova o atributo "CNPJ_Escola".
ALTER TABLE escola
DROP COLUMN cnpj_escola;

-- 25 Remova todos os registros da tabela "Instrutor”. OBS: Observe o que 
-- acontece com os registros das tabelas que recebem o atributo "InstrutorID" 
-- como foreign key.
DELETE FROM instrutor;

-- 26 Remova o atributo "InstrutorID" da tabela "Instrutor"
ALTER TABLE instrutor
DROP COLUMN instrutorid CASCADE;

-- 27 Remova a tabela "Instrutor".
DROP table instrutor CASCADE;

-- 28 Remova todas as tabelas do banco (esquema e conteúdo).
DROP SCHEMA public CASCADE;
CREATE SCHEMA public;

-- 29 Crie novamente as tabelas do banco de dados usando os scripts acima.

-- 30 Adicione um atributo "valor_hora" na tabela "Curso" tipo REAL.
ALTER TABLE curso
ADD COLUMN valor_hora TYPE REAL;

-- 31 Preencha o novo atributo “valor_hora” da tabela “Curso” com o valor 50 
-- (cada curso paga R$ 50,00 por hora ministrada).
UPDATE curso
SET valor_hora = 50;

-- 32 Crie uma nova tabela chamada “instrutor_pagamento” que contenha os seguintes 
-- atributos: (1) o id do instrutor ( PK - FK da tabela instrutor), (2) ano 
-- (PK - tipo INT) e (3) valor_pagamento (tipo REAL).
CREATE TABLE instrutor_pagamento (
  InstrutorID INT NOT NULL,
  ano INT NOT NULL,
  valor_pagamento REAL NOT NULL,

  CONSTRAINT InstrutorPagamentoAnoPK PRIMARY KEY (InstrutorID, ano),
  CONSTRAINT InstrutorPagamentoFK FOREIGN KEY (InstrutorID)
                                 REFERENCES instrutor(instrutorid)
);

-- 33 Insira na tabela "instrutor_pagamento" o valor que cada instrutor recebeu por ano.
SELECT i.instrutorid, sum(c.carga_horaria) AS total_horas
FROM turma AS t
  JOIN instrutor AS i
  ON t.instrutorid = i.instrutorid
JOIN curso AS c ON t.cursoid = c.cursoid
GROUP BY i.instrutorid;

-- 34 Faça uma trigger que atualiza o valor do pagamento do instrutor toda vez que inserirmos uma nova turma no sistema.
CREATE OR REPLACE FUNCTION atualiza_pgto_instrutor() RETURNS TRIGGER AS $trigger_pgt_instrutor$
   BEGIN
      INSERT INTO instrutor_pagamento
      (instrutorid, ano, valor_pagamento)
      VALUES (NEW.instrutorid, (SELECT date_part('year', (NEW.data_inicio))), 50);
      RETURN NEW;
   END;
$trigger_pgt_instrutor$ LANGUAGE plpgsql;
CREATE OR REPLACE TRIGGER trigger_up_pgt
  AFTER INSERT
  ON turma
  FOR EACH ROW
EXECUTE PROCEDURE atualiza_pgto_instrutor();

-- 35 Insira 3 turmas novas em 2019 para alguns instrutores e confira se sua trigger 
-- está funcionando e atualizando a tabela "instrutor_pagamento" corretamente
INSERT INTO Turma VALUES(1, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-06-15', 'YYYY-MM-DD'), 1, 1);