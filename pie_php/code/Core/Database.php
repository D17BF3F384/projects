<?php

$database =
'
DROP DATABASE IF EXISTS `piephp`;
CREATE DATABASE `piephp`;
USE `piephp`;

CREATE TABLE IF NOT EXISTS `users`(
    `id`              INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    `email`           VARCHAR(255) DEFAULT NULL,
    `password`        VARCHAR(255) DEFAULT NULL
);

INSERT INTO `users`(`email`, `password`) VALUES
    (\'thomashuynh@email.com\', \'$2y$10$itOoXKTnRljH9dRe/1q7juF88bMczwylNMEJy0Q1b0.g6Ldb0tErC\'),
    (\'nicolasren@email.com\', \'$2y$10$imWwwkoDoxzO37/EaT8Hueg3mKhgAPko8CvBA0Oe0RKF0FOosbVQW\'),
    (\'andryramanana@email.com\', \'$2y$10$BdMuoeSWxnGia0nGysawbeOp.uS6d0zqcbestH9ZdX0J21jr.4EYm\');
';

