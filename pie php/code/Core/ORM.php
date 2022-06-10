<?php

namespace Core;

class ORM {

    private $db;

    public function __construct() {
        $this->db = new \PDO("mysql:dbname=piephp;host=".DBHOST.";port:".DBPORT, DBUSER, DBPASSWORD);
    }

    public function create($table, $fields) {
        $request = "CREATE TABLE IF NOT EXISTS `".$table."`(\n";
        $request .= "\t`id` INT PRIMARY KEY NOT NULL AUTO_INCREMENT,\n";
        foreach($fields as $key => $value) {
            $request .= "\t`$key` VARCHAR(255) DEFAULT NULL,\n";
        }
        $request = substr($request, 0, -2);
        $request .= "\n);\n";
        $this->db->exec($request);
        $request = "INSERT INTO `".$table."`(";
        foreach($fields as $key => $value) {
            $request .= "`".$key."`, ";
        }
        $request = substr($request, 0, -2);
        $request .= ") VALUES\n\t(";
        foreach($fields as $key => $value) {
            $request .= "'".$value."', ";
        }
        $request = substr($request, 0, -2);
        $request .= ");\n";
        $this->db->exec($request);

        $request = "SELECT id FROM `".$table."` WHERE ";
        foreach($fields as $key => $value) {
            $request .= "`".$key."` = \"".$value."\" AND ";
        }
        $request = substr($request, 0, -5);
        $request .= ";";
        $request = $this->db->query($request)->fetch();
        return $request["id"];
    }

    public function read($table, $id) {
        $request = $this->db->query("DESCRIBE `".$table."`;")->fetchAll();
        $array1 = [];
        foreach($request as $key => $value) {
            array_push($array1, $request[$key]["Field"]);
        }
        $request = $this->db->query("SELECT * FROM `".$table."` WHERE id = ".$id.";")->fetchAll();
        $array2 = [];
        foreach($array1 as $key => $value) {
            $array2[$value] = $request[0][$value];
        }
        return $array2;
    }

    public function update($table, $id, $fields) {
        $request = "UPDATE `".$table."` SET ";
        foreach($fields as $key => $value) {
            $request .= "`".$key."` = \"".$value."\", ";
        }
        $request = substr($request, 0, -2);
        $request .= " WHERE `id` = ".$id.";";
        $this->db->exec($request);
        return true;
    }

    public function delete($table, $id) {
        $this->db->exec("DELETE FROM `".$table."` WHERE id = ".$id.";");
        return true;
    }

    public function find($table, $params = array(
        "WHERE" => "1",
        "ORDER BY" => "id ASC",
        "LIMIT" => ""
    )) {

    }

}

