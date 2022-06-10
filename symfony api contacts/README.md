-------------------------------------------------------|
    LANCER LE PROJET SUR SYMFONY 6
-------------------------------------------------------|

Étapes à suivre dans l'ordre :

- Run phpMyAdmin
- Run Apache2
- Run Postman
- Run MySQL
- Installer les dépendances avec "composer install"
- Set up les variables d'environnement dans le fichier .env, un exemple est donné
- Run "symfony serve"
- Set up la database : dans le navigateur lancer la route http://127.0.0.1:8000/reset/database

-------------------------------------------------------|
    TESTER AVEC POSTMAN
-------------------------------------------------------|

Le Json Body à ajouter pour les requêtes POST et PUT dans la section "Body"->"raw" :

{
    "firstname": "firstname test",
    "lastname": "lastname test",
    "email": "test@email.com",
    "address": "test",
    "age": "100",
    "phone": "0123456789"
}

CRUD :

http://127.0.0.1:8000/api/contacts/create
Crée un contact avec les données du Json Body.

http://127.0.0.1:8000/api/contacts
Affiche toutes les données de tous les contacts de la base de données.

http://127.0.0.1:8000/api/contacts/id=1
Affiche les données du contact dont l'id est 1 (exemple).

http://127.0.0.1:8000/api/contacts/firstname=robert
Affiche les données de tous les contacts qui ont dans leur prénom la chaîne de caractères "robert" (exemple).

et cetera pour les autres champs...

http://127.0.0.1:8000/api/contacts/edit/1
Met à jour les données du contact dont l'id est 1 avec les données du Json Body et renvoie 200. Si ce contact n'existe pas il sera créé (API REST) et renvoie 201.

http://127.0.0.1:8000/api/contacts/delete/1
Supprime le contact dont l'id est 1.

