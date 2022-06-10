<?php

namespace Model;

class UserModel extends \Core\Entity {

    // private $db;
    // private $id;
    // private $email;
    // private $password;

    // public function __construct($email, $password) {
    //     $this->db = new \PDO("mysql:dbname=piephp;host=".DBHOST.";port:".DBPORT, DBUSER, DBPASSWORD);
    //     $this->email = $email;
    //     $this->password = $password;
    // }

    public function save() {
        if($this->isEmailAvailable()) {
            $hash = password_hash($this->password, PASSWORD_DEFAULT);
            $this->db->exec("INSERT INTO `users`(`email`, `password`) VALUES('".$this->email."', '".$hash."');");
            $request = $this->db->query("SELECT `id` FROM `users` WHERE `email` = \"".$this->email."\";")->fetch();
            $this->id = $request[0];
            return true;
        }
        else return false;
    }

    public function isEmailAvailable() {
        $request = $this->db->query("SELECT `email` FROM `users` WHERE `email` = \"".$this->email."\";")->fetch();
        if($request) {
            if($request["email"] === $this->email) return false;
            else return true;
        }
        else return true;
    }

    public function read($column) {
        $request = $this->db->query("SELECT `".$column."` FROM `users` WHERE `id` = \"".$this->id."\";")->fetch();
        return $request[0];
    }

    public function update($column, $value) {
        $this->db->exec("UPDATE `users` SET `".$column."` = '".$value."' WHERE id = \"".$this->id."\";");
    }

    public function delete() {
        $this->db->exec("DELETE FROM `users` WHERE id = \"".$this->id."\";");
    }

    public function read_all() {
        $request = $this->db->query("SELECT * FROM `users` WHERE `id` = \"".$this->id."\";")->fetch();
        $array = [];
        $array["id"] = $request["id"];
        $array["email"] = $request["email"];
        $array["password"] = $request["password"];
        return $array;
    }

    public function loginCheck() {
        if(!$this->isEmailAvailable()) {
            $request = $this->db->query("SELECT `id` FROM `users` WHERE `email` = \"".$this->email."\";")->fetch();
            $this->id = $request[0];
            $password = $this->read("password");
            if(password_verify($this->password, $password)) {
                session_start();
                $_SESSION["id"] = $this->id;
                $_SESSION["email"] = $this->email;
                $_SESSION["password"] = $this->password;
            }
        }

    }

}

