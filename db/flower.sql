BEGIN TRANSACTION;
DROP TABLE IF EXISTS "Users";
DROP TABLE IF EXISTS "Composition_flower";
DROP TABLE IF EXISTS "Order";
DROP TABLE IF EXISTS "Order_cost";
DROP TABLE IF EXISTS "Flower";
DROP TABLE IF EXISTS "Composition";
CREATE TABLE IF NOT EXISTS "Users" (
	"id"	INTEGER,
	"login"	Text NOT NULL UNIQUE,
	"password"	Text NOT NULL,
	"role"	Text NOT NULL,
	CONSTRAINT "unique_id" UNIQUE("id"),
	PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "Composition_flower" (
	"id"	INTEGER,
	"id_flower"	Integer NOT NULL,
	"composition_id"	Integer NOT NULL,
	"flower_count"	Integer,
	PRIMARY KEY("id" AUTOINCREMENT),
	CONSTRAINT "lnk_Flower_Composition_flower" FOREIGN KEY("id_flower") REFERENCES "Flower"("id"),
	CONSTRAINT "lnk_Composition_Composition_flower" FOREIGN KEY("composition_id") REFERENCES "Composition"("id")
);
CREATE TABLE IF NOT EXISTS "Order" (
	"id"	INTEGER,
	"composition_count"	Integer NOT NULL,
	"order_date"	Date NOT NULL,
	"release_date"	Date NOT NULL,
	"user_id"	Integer NOT NULL,
	"composition_id"	INTEGER,
	PRIMARY KEY("id" AUTOINCREMENT),
	CONSTRAINT "lnk_Users_Order" FOREIGN KEY("user_id") REFERENCES "Users"("id")
);
CREATE TABLE IF NOT EXISTS "Order_cost" (
	"id"	INTEGER,
	"order_id"	Integer NOT NULL,
	"cost"	INTEGER NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT),
	CONSTRAINT "unique_id" UNIQUE("id"),
	CONSTRAINT "lnk_Order_Order_cost" FOREIGN KEY("order_id") REFERENCES "Order"("id")
);
CREATE TABLE IF NOT EXISTS "Flower" (
	"id"	INTEGER,
	"flower_name"	Text NOT NULL,
	"variety"	Text NOT NULL,
	"flower_cost"	INTEGER NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT),
	CONSTRAINT "unique_id" UNIQUE("id")
);
CREATE TABLE IF NOT EXISTS "Composition" (
	"id"	INTEGER,
	"composition_name"	Text NOT NULL,
	"composition_cost"	INTEGER,
	CONSTRAINT "unique_id" UNIQUE("id"),
	PRIMARY KEY("id" AUTOINCREMENT)
);
INSERT INTO "Users" VALUES (1,'sonyands04','zd5mby','S');
INSERT INTO "Users" VALUES (2,'valyaksh2003','9Met66','A');
INSERT INTO "Users" VALUES (3,'roboway','zge8yq','S');
INSERT INTO "Users" VALUES (4,'sunny_day_88','smile1234','S');
INSERT INTO "Users" VALUES (5,'MidnightDreamer87','WhStar369','S');
INSERT INTO "Users" VALUES (6,'SparklingMind33','SecretWisdom2024','S');
INSERT INTO "Users" VALUES (7,'user123','12168229833180737748','S');
INSERT INTO "Users" VALUES (8,'hello23','9934520233202095969','S');
INSERT INTO "Users" VALUES (9,'sonyands','422025119395029033','S');
INSERT INTO "Users" VALUES (10,'user15','5565554274247862708','S');
INSERT INTO "Users" VALUES (11,'user24','13205102576593733992','S');
INSERT INTO "Users" VALUES (12,'user57','11548656963390143488','S');
INSERT INTO "Users" VALUES (13,'sdfasfd','9934520233202095969','S');
INSERT INTO "Composition_flower" VALUES (1,1,1,4);
INSERT INTO "Composition_flower" VALUES (2,2,2,6);
INSERT INTO "Composition_flower" VALUES (3,3,2,9);
INSERT INTO "Composition_flower" VALUES (4,4,2,2);
INSERT INTO "Composition_flower" VALUES (5,5,2,1);
INSERT INTO "Composition_flower" VALUES (6,6,3,2);
INSERT INTO "Composition_flower" VALUES (7,7,3,1);
INSERT INTO "Composition_flower" VALUES (8,3,3,3);
INSERT INTO "Composition_flower" VALUES (9,2,3,1);
INSERT INTO "Composition_flower" VALUES (10,8,4,3);
INSERT INTO "Composition_flower" VALUES (11,5,4,3);
INSERT INTO "Composition_flower" VALUES (12,2,5,9);
INSERT INTO "Order" VALUES (1,2,'07-04-2024','10-04-2024',1,1);
INSERT INTO "Order" VALUES (2,1,'06-04-2024','06-04-2024',3,2);
INSERT INTO "Order_cost" VALUES (1,1,790);
INSERT INTO "Order_cost" VALUES (2,2,434);
INSERT INTO "Flower" VALUES (1,'Rose peony','Rose',20);
INSERT INTO "Flower" VALUES (2,'Peony bush rose','Rose',10);
INSERT INTO "Flower" VALUES (3,'Pink carnation','Carnation',6);
INSERT INTO "Flower" VALUES (4,'Eustoma white','Eustoma',12);
INSERT INTO "Flower" VALUES (5,'Eucalyptus Cinerea','Eucalyptus',10);
INSERT INTO "Flower" VALUES (6,'White lilac','Lilac',9);
INSERT INTO "Flower" VALUES (7,'Rose French','Rose',12);
INSERT INTO "Flower" VALUES (8,'Ranunculus pink','Ranunculus',21);
INSERT INTO "Composition" VALUES (1,'Security',234);
INSERT INTO "Composition" VALUES (2,'Бархат',123);
INSERT INTO "Composition" VALUES (3,'Charm',2000);
INSERT INTO "Composition" VALUES (4,'Ханой',3433);
INSERT INTO "Composition" VALUES (5,'Нежность любви',233);
COMMIT;
