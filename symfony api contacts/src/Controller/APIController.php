<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Serializer\Normalizer\ObjectNormalizer;
use Symfony\Component\Serializer\Encoder\JsonEncoder;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Serializer\Serializer;
use Doctrine\Persistence\ManagerRegistry;
use App\Repository\ContactRepository;
use App\Entity\Contact;

#[Route(path: '/api', name: 'api')]
class APIController extends AbstractController
{

    public function __construct()
    {
        $this->db = new \PDO("mysql:dbname=".$_ENV['DBNAME'].";host=".$_ENV['DBHOST'].";port:".$_ENV['DBPORT'], $_ENV['DBUSER'], $_ENV['DBPASSWORD']);
    }

    public function getColumnsFromTable($table)
    {
        $request = 'DESCRIBE `'.$table.'`;';
        $request = $this->db->query($request)->fetchAll();
        $array = [];
        foreach($request as $key => $value)
        {
            array_push($array, $value[0]);
        }
        return $array;
    }

    public function getAssociativeArrayFromFetchAll($request, $table)
    {
        $array = $this->getColumnsFromTable($table);
        $associativeArray = [];
        foreach($request as $key1 => $value1)
        {
            foreach($array as $key2 => $value2)
            {
                $associativeArray[$key1][$value2] = $value1[$value2];
            }
        }
        return $associativeArray;
    }

    /*--------------------*\
        CREATE
    \*--------------------*/

    #[Route(path: '/contacts/create', name: 'create_contact', methods: 'POST')]
    public function createContacts(Request $request, ManagerRegistry $doctrine)
    {
        // if($request->isXmlHttpRequest())
        // {
            $data = json_decode($request->getContent());
            $contact = new Contact();
    
            $contact->setFirstname($data->firstname);
            $contact->setLastname($data->lastname);
            $contact->setEmail($data->email);
            $contact->setAddress($data->address);
            $contact->setAge($data->age);
            $contact->setPhone($data->phone);
            $entityManager = $doctrine->getManager();
            $entityManager->persist($contact);
            $entityManager->flush();
    
            return new Response("Done", 201);
        // }
        // return new Response("Error", 404);

    }

    /*--------------------*\
        READ
    \*--------------------*/

    #[Route(path: '/contacts', name: 'get_contacts', methods: 'GET')]
    public function showContacts(ContactRepository $ContactsRepository)
    {
        $contacts = $ContactsRepository->findAll();
        $encoders = [new JsonEncoder()];
        $normalizers = [new ObjectNormalizer()];
        $serializer = new Serializer($normalizers, $encoders);
        $jsonContent = $serializer->serialize
        (
            $contacts, "json",
            [
                "circular_reference_handler" => function($object)
                {
                    return $object->getId();
                }
            ]
        );
        $response = new Response($jsonContent);
        $response->headers->set("Content-Type", "application/json");
        return $response;
    }

    #[Route(path: '/contacts/id={id}', name: 'get_contact_by_id', methods: 'GET')]
    public function getContact(Contact $contact)
    {
        $encoders = [new JsonEncoder()];
        $normalizers = [new ObjectNormalizer()];
        $serializer = new Serializer($normalizers, $encoders);
        $jsonContent = $serializer->serialize($contact, "json", [
            "circular_reference_handler" => function($object) {
                return $object->getId();
            }
        ]);
        $response = new Response($jsonContent);
        $response->headers->set("Content-Type", "application/json");
        return $response;
    }

    #[Route(path: '/contacts/firstname={firstname}', name: 'contacts_first_name', methods: 'GET')]
    public function showContactsFirstName($firstname)
    {
        $request = 'SELECT * FROM `contact` WHERE `firstname` LIKE "%'.$firstname.'%";';
        $request = $this->db->query($request)->fetchAll();
        $request = $this->getAssociativeArrayFromFetchAll($request, 'contact');
        $response = new JsonResponse($request);
        $response->setEncodingOptions($response->getEncodingOptions() | JSON_PRETTY_PRINT);
        return $response;
    }

    #[Route(path: '/contacts/lastname={lastname}', name: 'contacts_last_name', methods: 'GET')]
    public function showContactsLastName($lastname)
    {
        $request = 'SELECT * FROM `contact` WHERE `lastname` LIKE "%'.$lastname.'%";';
        $request = $this->db->query($request)->fetchAll();
        $request = $this->getAssociativeArrayFromFetchAll($request, 'contact');
        $response = new JsonResponse($request);
        $response->setEncodingOptions($response->getEncodingOptions() | JSON_PRETTY_PRINT);
        return $response;
    }

    #[Route(path: '/contacts/email={email}', name: 'contacts_email', methods: 'GET')]
    public function showContactsEmail($email)
    {
        $request = 'SELECT * FROM `contact` WHERE `email` LIKE "%'.$email.'%";';
        $request = $this->db->query($request)->fetchAll();
        $request = $this->getAssociativeArrayFromFetchAll($request, 'contact');
        $response = new JsonResponse($request);
        $response->setEncodingOptions($response->getEncodingOptions() | JSON_PRETTY_PRINT);
        return $response;
    }

    #[Route(path: '/contacts/address={address}', name: 'contacts_address', methods: 'GET')]
    public function showContactsAddress($address)
    {
        $request = 'SELECT * FROM `contact` WHERE `address` LIKE "%'.$address.'%";';
        $request = $this->db->query($request)->fetchAll();
        $request = $this->getAssociativeArrayFromFetchAll($request, 'contact');
        $response = new JsonResponse($request);
        $response->setEncodingOptions($response->getEncodingOptions() | JSON_PRETTY_PRINT);
        return $response;
    }

    #[Route(path: '/contacts/phone={phone}', name: 'contacts_phone', methods: 'GET')]
    public function showContactsPhone($phone)
    {
        $request = 'SELECT * FROM `contact` WHERE `phone` LIKE "%'.$phone.'%";';
        $request = $this->db->query($request)->fetchAll();
        $request = $this->getAssociativeArrayFromFetchAll($request, 'contact');
        $response = new JsonResponse($request);
        $response->setEncodingOptions($response->getEncodingOptions() | JSON_PRETTY_PRINT);
        return $response;
    }

    /*--------------------*\
        UPDATE
    \*--------------------*/

    #[Route(path: '/contacts/edit/{id}', name: 'edit_contact', methods: 'PUT')]
    public function editContacts(?Contact $contact, Request $request, ManagerRegistry $doctrine)
    {
        // if($request->isXmlHttpRequest())
        // {
            $data = json_decode($request->getContent());
            $code = 200;

            if(!$contact)
            {
                $contact = new Contact();
                $code = 201;
            }
    
            $contact->setFirstname($data->firstname);
            $contact->setLastname($data->lastname);
            $contact->setEmail($data->email);
            $contact->setAddress($data->address);
            $contact->setAge($data->age);
            $contact->setPhone($data->phone);
            $entityManager = $doctrine->getManager();
            $entityManager->persist($contact);
            $entityManager->flush();
    
            return new Response("Done", $code);
        // }
        // return new Response("Error", 404);

    }

    /*--------------------*\
        DELETE
    \*--------------------*/

    #[Route(path: '/contacts/delete/{id}', name: 'delete_contact', methods: 'DELETE')]
    public function deleteContact(Contact $contact, ManagerRegistry $doctrine)
    {
        $entityManager = $doctrine->getManager();
        $entityManager->remove($contact);
        $entityManager->flush();
        return new Response("Done");
    }
}

