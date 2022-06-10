<?php

namespace Core;

class Entity {

    private static $relations = [];

    public function __construct($array) {
        $this->db = new \PDO("mysql:dbname=piephp;host=".DBHOST.";port:".DBPORT, DBUSER, DBPASSWORD);
        foreach($array as $key => $value) {
            $this->$key = $value;
        }
    }

}

