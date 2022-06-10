DROP DATABASE IF EXISTS `api-contact`;
CREATE DATABASE IF NOT EXISTS `api-contact`;
USE `api-contact`;

CREATE TABLE `contact`(
    `id` INT PRIMARY KEY AUTO_INCREMENT,
    `firstname` VARCHAR(255) DEFAULT NULL,
    `lastname` VARCHAR(255) DEFAULT NULL,
    `email` VARCHAR(255) DEFAULT NULL,
    `address` VARCHAR(255) DEFAULT NULL,
    `age` INT DEFAULT NULL,
    `phone` VARCHAR(255) DEFAULT NULL
);

INSERT INTO `contact`(`firstname`, `lastname`, `email`, `address`, `age`, `phone`) VALUES
    ('Robert', 'Anderson', 'robertanderson@email.com', 'Paris', 10, '+1-202-918-2132'),
    ('Christy', 'Walton', 'christywalton@email.com', 'Lyon', 20, '+1-202-555-0164'),
    ('Susan', 'Marsh', 'susanmarsh@email.com', 'Bordeaux', 30, '+1-202-555-0193'),
    ('Steven', 'Sutton', 'stevensutton', 'Marseille', 40, '+1-202-555-0118'),
    ('David', 'Medina', 'davidmedina@email.com', 'Strasbourg', 50, '+1-202-555-0106'),
    ('Michael', 'Andrews', 'michaelandrews@email.com', 'Lille', 60, '+1-202-555-0189'),
    ('Randy', 'Oconnor', 'randyoconnor@email.com', 'Amiens', 70, '+1-202-555-0120'),
    ('Lance', 'Cervantes', 'lancecervantes@email.com', 'Toulon', 80, '+1-202-555-0153'),
    ('Robert', 'Lapis', 'robertlapis@email.com', 'Saint-Tropez', 90, '+1-208-897-3483'),
    ('Samantha', 'Gomez', 'samanthagomez@email.com', 'Nice', 100, '+1-202-555-0181'),
    ('Jean-Baptiste', 'Poquelin', 'jeanbaptistepoquelin@email.com', 'Versailles', 110, '+1-123-867-0199'),
    ('Joan', 'Bennett', 'joanbennett@email.com', 'Cannes', 120, '+1-202-555-0157');

