-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: guanabaris
-- ------------------------------------------------------
-- Server version	8.0.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `tbvendas`
--

DROP TABLE IF EXISTS `tbvendas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tbvendas` (
  `venda` int NOT NULL AUTO_INCREMENT,
  `data_venda` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `produtos` varchar(300) NOT NULL,
  `valor` decimal(10,2) NOT NULL,
  `vendedor` varchar(30) NOT NULL,
  `idcli` int NOT NULL,
  PRIMARY KEY (`venda`),
  KEY `idcli` (`idcli`),
  CONSTRAINT `tbvendas_ibfk_1` FOREIGN KEY (`idcli`) REFERENCES `tbclientes` (`idcli`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tbvendas`
--

LOCK TABLES `tbvendas` WRITE;
/*!40000 ALTER TABLE `tbvendas` DISABLE KEYS */;
INSERT INTO `tbvendas` VALUES (2,'2022-11-28 15:05:02','bolacha R$5,99',5.99,'Administrador',1),(4,'2022-11-28 15:22:29','Lava louça limpol neutro   R$ 3.49\nBolacha   R$ 6.99\n',10.48,'Administrador',1),(5,'2022-11-28 15:27:01','Lava louça limpol neutro   R$ 3.49\nBolacha   R$ 6.99\nLava louça limpol neutro   R$ 3.49\nBolacha   R$ 6.99\n',20.96,'Administrador',3);
/*!40000 ALTER TABLE `tbvendas` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-11-28 19:05:42
