# ProjetPOO

Une toute nouvelle Startup de livraison souhaite se développer. Son cœur d’activité est la vente en ligne de composants électroniques. Nous devons concevoir et réaliser une application permettant la gestion informatique de ses affaires.

### Prérequis

Voici les prérequis pour utiliser notre application: 

- Un ordinateur
- Une connexion Internet
- Un compte Utilisateur 


### Installation

Pour installer l'application, il suffit de télécharger le fichier Projet.exe situé dans la branche Projet_Final.

## Démarrage

Pour lancer l'application, il faut double-cliquer sur le fichier précédemment téléchargé.

## Utilisation de l'application: 

### I) Connection

Pour des raisons évidentes de sécurité, l'utilisation de l'application nécessite de se connecter avec une adresse email ainsi qu'un mot de passe situé dans la BDD.

### II) Les catégories
L'application permet la gestion de plusieurs catégories de données:
  - Le Personnel de l'entreprise
  - Les Clients
  - Les Commandes des Clients
  - Le Stock d'Article disponibles
  - Les différentes Statistiques (cas particulier)
 
 __Attention, pour accéder à la catégorie Personnel, l'utilisateur doit être le supérieur hiérarchique de quelqu'un.__

### III) Les actions
Pour chaque catégorie (sauf statistique), l'utilisateur peut faire 4 actions:
  - Afficher
  - Ajouter
  - Modifier
  - Supprimer

### IV) Les zones de texte
Pour chacune des actions, l'utilisateur doit renter des données dans des zones de texte. Chacune de ces zones est agrémenté de label permettant de savoir quelle donnée rentrer.

### V) La catégorie statistique
La dernière catégorie, Statistique, est un peu particulière. Elle permet d'accéder à un certain nombre de statistique (comme son nom l'indique):

  - Calculer le panier moyen
  - Calculer le chiffre d’affaire sur un mois en particulier
  - Identifier les produits sous le seuil de réapprovisionnement
  - Calculer le montant total des achats pour un client
  - Identifier les 10 articles les plus vendus
  - Identifier les 10 articles les moins vendus
  - Calculer la valeur commerciale du stock
  - Calculer la valeur d’achat du stock
  - Simuler des variations de valeurs commerciales pour en déduire la valeur du stock

Pour cette dernière statistique, l'utilisateur doit rentrer 4 données différentes:
  - La TVA (20%, 10% ou 5.5%)
  - Une marge commerciale (5%, 10% ou 15%)
  - Une remise commerciale (5% ou 6%)
  - Une démarque inconnue (2%, 3% ou 5%)

Chacune de ces valeurs peut également rester vide.

## Test Unitaire

Voici une démonstration en image de notre application:

### Etape 1: Se connecter

![2](https://user-images.githubusercontent.com/78081509/144502482-c695e396-b20b-4809-8131-10b116e4f0ff.png)

### Etape 2: Selectionner la catégorie (ici Commande)

![3](https://user-images.githubusercontent.com/78081509/144502652-40354654-5710-421f-9f30-a748ac437289.png)

### Etape 3: Selectionner l'action (ici Afficher)

![4](https://user-images.githubusercontent.com/78081509/144502959-da5b818e-f61d-46a4-a4c8-634d5973f70d.png)


### Etape 4: Remplir le/les zone(s) de texte

![5](https://user-images.githubusercontent.com/78081509/144503110-e24d4282-2bce-4f18-99cc-872dbfb32e51.png)

### Etape 5: Appuyer sur Valider et admirer le résultat

![6](https://user-images.githubusercontent.com/78081509/144503176-83dc4a34-8fa6-4646-94a2-e6019fe5b4c5.png)

## Cette application a été créée à l'aide de :

* [Visual Paradigm](https://www.visual-paradigm.com/): Conception du Projet
* [Github](https://github.com/): Plateforme de gestion de projet
* [Visual Studio et Visual Studio Code](https://visualstudio.microsoft.com/fr/): IDE de programmation
* [Microsoft Azure](https://portal.azure.com/): Hébergement de Base de Donnée
* [Microsoft SQL Service Management Studio (SSMS)](https://docs.microsoft.com/fr-fr/sql/ssms/download-sql-server-management-studio-ssms?view=sql-server-ver15): Gestion de Base de Donnée

## Auteurs
Voici tous les créateurs du Projet:
* **Olivier Gosset** _alias_ [@P3mast](https://github.com/P3mast)
* **Hugo Dehurtevent** _alias_ [@Hugodehu](https://github.com/Hugodehu)
* **Kylian Renault** _alias_ [@Gammelinne](https://github.com/Gammelinne)
* **Charles Lefranc** _alias_ [@SourcierDeVerite](https://github.com/SourcierDeVerite)
