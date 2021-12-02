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
 
![image](https://user-images.githubusercontent.com/78081509/144478681-b7d65517-00ff-41a0-923d-47a6fd3e91de.png) Pour accéder à la catégorie Personnel, l'utilisateur doit être le supérieur hiérarchique de quelqu'un.

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
