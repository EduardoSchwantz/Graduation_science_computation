create database servicosUf;
use servicosUf;

create table tbusuarios(
iduser int primary key not null auto_increment,
usuario varchar(50) not null,
login varchar(15) not null unique,
senha varchar(15) not null
); 
desc tbusuarios;
insert into tbusuarios(iduser, usuario, login, senha)
values
(default, 'Administrador', 'admin', 'admin'),
(default, 'Eduardo Schwantz', 'eduardoschwantz', '1234'),
(default, 'Cecilia Botelho', 'ceciliabotelho', '1234');

select * from tbusuarios;

create table tbclientes(
idcli int primary key auto_increment,
nomecli varchar(50) not null unique,
endcli varchar(100),
fonecli varchar(50) not null,
emailcli varchar(50)
);
desc tbclientes;

insert into tbclientes(nomecli, endcli, fonecli, emailcli)
values
('Linus Totbclientesrvalds', 'Rua tux, 2015', '9999-9999', 'linus@linux.com');
select * from tbclientes;
select idcli as id, nomecli as nome, endcli as endereço, fonecli as fone, emailcli as email from tbclientes;

create table tbos(
os int primary key auto_increment,
data_os timestamp default current_timestamp,
equipamento varchar(150) not null,
defeito varchar(150) not null,
servico varchar(150),
tecnico varchar(30),
valor decimal(10,2),
idcli int not null,
foreign key (idcli) references tbclientes(idcli)
);
desc tbos;
insert into tbos (equipamento, defeito, servico, tecnico, valor, idcli)
values
('Notebook', 'Não liga!', 'Troca da fonte', 'Cecilia', 87.50, 1);
select * from tbos;

select
O.os, equipamento, defeito, servico, valor,
C.nomecli, fonecli
from tbos as O
inner join tbclientes as C
on (O.idcli = C.idcli);

select * from tbusuarios where login='admin' and senha='admin';

desc tbusuarios;
alter table tbusuarios
add column perfil varchar(20) not null;
update tbusuarios set perfil = 'admin' where iduser = 1;
update tbusuarios set perfil = 'user' where iduser = 2;
update tbusuarios set perfil = 'user' where iduser = 3;
alter table tbclientes add unique(nomecli);