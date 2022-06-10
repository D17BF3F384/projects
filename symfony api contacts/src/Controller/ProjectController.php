<?php

namespace App\Controller;

use Symfony\Component\HttpFoundation\Response;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;

class ProjectController extends AbstractController
{

    public function __construct()
    {
        $this->db = new \PDO("mysql:dbname=".$_ENV['DBNAME'].";host=".$_ENV['DBHOST'].";port:".$_ENV['DBPORT'], $_ENV['DBUSER'], $_ENV['DBPASSWORD']);
    }

    #[Route(path: '/home', name: 'home')]
    public function showHome(): Response
    {
        return $this->render("home.html.twig", []);
    }

    #[Route(path: '/reset/database', name: 'reset_database')]
    public function reset_database(): Response
    {
        $this->db->exec(file_get_contents("../public/database.sql"));
        return $this->redirectToRoute('home');
    }

}

