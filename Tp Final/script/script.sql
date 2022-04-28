create database buena_pata;

create table localidad(cod_postal int primary key, nombre varchar(60));

create table especie(codigo serial primary key, nombre varchar(40));

create table cliente(dni int primary key, nombres varchar(80), apellido varchar(90), domicilio varchar(120), telefono varchar(20),cod_postal int,  observaciones varchar(250));

alter table cliente add constraint fk_cliente_localidad foreign key(cod_postal) references localidad(cod_postal);

create table profesional(dni int primary key, matricula varchar(10),nombres varchar(80), apellido varchar(90), domicilio varchar(120), telefono varchar(20),cod_postal int,  observaciones varchar(250));

alter table profesional add constraint fk_profesional_localidad foreign key(cod_postal) references localidad(cod_postal);

create table mascota(codigo serial primary key, nombre varchar(80), fecha_nac Date, dni_cliente int, cod_especie int, vacunado bit, observaciones varchar(250));

alter table mascota add constraint fk_mascota_especie foreign key(cod_especie) references especie(codigo);
alter table mascota add constraint fk_mascota_cliente foreign key(dni_cliente) references cliente(dni);

-- tabla que registra los diferentes tratamientos segun la especie
create table tratamiento(codigo serial primary key, descripcion varchar(100), cod_especie int);
alter table tratamiento add constraint fk_tratamiento_especie foreign key(cod_especie) references especie(codigo);

create table medicamento(codigo serial primary key, descripcion varchar(100), cod_especie int, importe float, cantidad int);
alter table medicamento add constraint fk_medicamento_especie foreign key(cod_especie) references especie(codigo);

--registra los tipos de enfermedades que puede tener una mascota.
create table diagnostico (codigo serial primary key, nombre varchar(60));

create table consulta(codigo serial primary key, fecha date, hora timestamp, dni_prof int, cod_mascota int, asistio smallint, cod_diag int, observaciones varchar(150));
alter table consulta add constraint fk_consulta_prof foreign key(dni_prof) references profesional(dni);
alter table consulta add constraint fk_consulta_mascota foreign key(cod_mascota) references mascota(codigo);
alter table consulta add constraint fk_consulta_diagnostico foreign key(cod_diag) references diagnostico(codigo);

create table mascota_tratamiento(codigo serial primary key,cod_consulta int, cod_tratamiento int, fecha_desde date, fecha_hasta date );
alter table mascota_tratamiento add constraint fk_mascota_tratamiento_consulta foreign key(cod_consulta) references consulta(codigo);
alter table mascota_tratamiento add constraint fk_mascota_tratamiento_tratamiento foreign key(cod_tratamiento) references tratamiento(codigo);

create table mascota_medicamento(codigo serial primary key, cod_tratamiento int, cod_medicamento int, cantidad float);
alter table mascota_medicamento add constraint fk_mascota_medicamento_tratamiento foreign key(cod_tratamiento) references tratamiento(codigo);
alter table mascota_medicamento add constraint fk_mascota_medicamento_medicamento foreign key(cod_medicamento) references medicamento(codigo);
-- insercion de informacion
insert into localidad(cod_postal,nombre) values(9100, 'Trelew'),(9103,'Rawson');
insert into especie(nombre) values('canino'),('felino'),('ave'),('reptil');

--ejemplo de insercion de cliente
INSERT INTO cliente(dni, nombres, apellido, domicilio, telefono, cod_postal, observaciones)
    VALUES (44321654,'Jose','Martinez','mitre 2334','44321654',9100,'');
