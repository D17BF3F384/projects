<?php

define("DBHOST", "localhost");
define("DBUSER", "user");
define("DBPASSWORD", "");
define("DBNAME", "mysql");
define("DBPORT", "3306");

try {
    $db = new PDO("mysql:dbname=".DBNAME.";host=".DBHOST.";port:".DBPORT, DBUSER, DBPASSWORD);
    $db->exec("SET NAMES utf8");
}
catch(PDOException $e) {
    die($e->getMessage());
}

require_once "Core/Database.php";
$db->exec($database);

