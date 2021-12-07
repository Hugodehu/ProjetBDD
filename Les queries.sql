PERSONNEL

Ajout personnel

"USE DB_test; INSERT INTO Personnel(Personnel.nom, Personnel.prenom, Personnel.date_embauche, Personnel.superieur) VALUES ('" + this->getNom() + "', '" + this->getPrenom() + "', '" + this->getDate() + "', '" + this->getSuperieur() + "');";

INSERT INTO Authentification (email, mot_de_passe)
VALUES ('test666@gmail.com', 'azertyyyyyy')

INSERT INTO Adresse(rue, id_ville)
Select 'test666', Ville.id_ville 
FROM Ville 
WHERE nom='Shamokin';

INSERT INTO Personnel (nom, prenom, date_embauche, superieur, id_personnel_Encadre_par, id_adresse, id_authentification) 
select 'valeur 54', 'valeur 2',1991-05-04, 0, 42, Adresse.id_adresse, Authentification.id_authentification 
from Adresse, Authentification
where Adresse.rue = 'test666' and Authentification.email = 'test666@gmail.com';


Suppression personnel

USE LAVRAI_DB_test; 

CREATE TABLE #DeletePersonnel(Id int Not NULL primary key, Id_authentification int NOT NULL, Id_adresse int NOT NULL, nom char (30), prenom char(30))
INSERT INTO #DeletePersonnel
SELECT Personnel.id_personnel, Personnel.id_authentification, Personnel.nom, Personnel.prenom from Personnel
WHERE(id_personnel = 49 AND nom = 'Haney' AND prenom = 'Shanon') 

DELETE FROM Personnel WHERE id_personnel IN(SELECT #DeletePersonnel.Id FROM #DeletePersonnel WHERE #DeletePersonnel.Id = 49  AND #DeletePersonnel.nom = 'Haney' AND #DeletePersonnel.prenom = 'Shanon')

DELETE FROM dbo.Authentification WHERE id_authentification IN(SELECT #DeletePersonnel.id_authentification FROM #DeletePersonnel WHERE #DeletePersonnel.Id = 49 AND #DeletePersonnel.nom = 'Haney' AND #DeletePersonnel.prenom = 'Shanon')

DELETE FROM Adresse WHERE id_adresse IN(SELECT #DeletePersonnel.id_adresse FROM #DeletePersonnel WHERE #DeletePersonnel.Id = 49 AND #DeletePersonnel.nom = 'Haney' AND #DeletePersonnel.prenom = 'Shanon');

DROP TABLE #DeletePersonnel



Afficher personnel

SELECT id_personnel, Personnel.nom, prenom, Ville.nom Nom_de_la_ville, Ville.code_postal, Adresse.rue, date_embauche, superieur
FROM Personnel
INNER JOIN Adresse ON Adresse.id_adresse = Personnel.id_adresse
INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville
WHERE(Adresse.id_adresse = Personnel.id_adresse AND Personnel.id_personnel = id_personnel AND Personnel.nom = 'nomPersonnel' AND prenom = 'prenomPrenom');



Modifier personnel

USE LAVRAI_DB_test

UPDATE Personnel
SET Personnel.nom = 'DR. XXXXXX', Personnel.prenom = 'douze',  Personnel.date_embauche = 2020-02-07, Personnel.superieur = 0

FROM Personnel
WHERE Personnel.id_personnel = 2;

UPDATE Adresse
SET Adresse.rue = 'quarante douze',Adresse.id_ville = Ville.id_ville
FROM Adresse
INNER JOIN Personnel ON Personnel.id_adresse = Adresse.id_ville
INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville
WHERE Adresse.id_adresse = Personnel.id_adresse AND Personnel.id_personnel = 2 AND Personnel.nom = 'DR. XXXXXX' AND Personnel.prenom = 'douze' AND Ville.nom = 'Shamokin' AND Ville.code_postal = '78705'

UPDATE Authentification
SET Authentification.email = 'DR. @LER.Roland', mot_de_passe = 'jbiqbghqsbfbhF'
FROM Authentification
INNER JOIN Personnel ON Personnel.id_authentification = Authentification.id_authentification
WHERE Authentification.id_authentification = Personnel.id_authentification AND Personnel.id_personnel = 2 AND Personnel.nom = 'DR. XXXXXX' AND Personnel.prenom = 'douze'
	vérifié fait



CLIENT

Ajout client

USE LAVRAI_DB_test

INSERT INTO Client (nom, prenom, date_naissance, date_premiere_commande) 
Values ('Michelle', 'Miche',1991-05-04, 1991-05-04); 


INSERT INTO Adresse(rue, id_ville, id_client)
select 'laruelavraie', Ville.id_ville, Client.id_client
FROM Ville, Client
WHERE Ville.nom='Shamokin' and Client.nom = 'Michelle' and Client.prenom = 'Miche';

INSERT INTO Adresse(rue, id_ville, id_client_Livrer)
select 'laruelavraie', Ville.id_ville, Client.id_client
FROM Ville, Client
WHERE Ville.nom='Shamokin' and Client.nom = 'Michelle' and Client.prenom = 'Miche';
	vérifié

Suppression client

USE LAVRAI_DB_test

DELETE FROM Adresse WHERE Adresse.id_client IN(SELECT Client.id_client FROM Client WHERE Client.id_client = 1099 AND Client.nom = 'Michelle' AND Client.prenom = 'Miche')
OR id_client_Livrer IN(SELECT Client.id_client FROM Client WHERE Client.id_client = 1099 AND Client.nom = 'Michelle' AND Client.prenom = 'Miche');

DELETE FROM Client WHERE Client.id_client IN(SELECT  Client.id_client FROM Client WHERE Client.id_client = 1099  AND Client.nom = 'Michelle' AND Client.prenom = 'Miche')
	vérifié
	

Afficher client

USE LAVRAI_DB_test;

SELECT Client.id_client, client.nom, Client.prenom, Ville.nom Nom_de_la_ville, Ville.code_postal, Adresse.rue
FROM Client
INNER JOIN Adresse ON Adresse.id_client = Client.id_client 
INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville
WHERE(Adresse.id_client = Client.id_client AND Client.id_client = 2 AND Client.nom = 'Welker' AND Client.prenom = 'Camila');


Modifier client

USE LAVRAI_DB_test

UPDATE Adresse
SET Adresse.rue = 'quarante douze',Adresse.id_ville = Ville.id_ville
FROM Adresse
INNER JOIN Client ON Client.id_client = Adresse.id_client
INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville
WHERE Adresse.id_client = Client.id_client AND Client.id_Client = 29 AND Client.nom = 'Satr' AND prenom = 'foulah' AND Ville.nom = 'Huntington Park' AND Ville.code_postal = '25502'

UPDATE Client
SET Client.nom = 'Satr', Client.prenom = 'foulah',  Client.date_naissance = 2020-02-07, Client.date_premiere_commande = 2020-02-07
FROM CLient
INNER JOIN Adresse ON Adresse.id_client = Client.id_client OR Adresse.id_client_Livrer = Client.id_client
INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville
WHERE Adresse.id_client = Client.id_client AND Client.id_Client = 29 AND Client.nom = 'DR. XXXXXX' AND prenom = 'douze' AND Ville.nom = 'Huntington Park' AND Ville.code_postal = '25502'





COMMANDE

Ajout commande produit

use LAVRAI_DB_test

Insert into Commande (reference, date_livraison, date_emission, prix_HT, prix_TTC, TVA, remise, prix_final,  id_client)
select 'Salade5', 1995-05-04, 1994-05-04, 0, 0, 0, 25, 0, Client.id_client
from Client
where (Client.nom = 'Welker' and Client.prenom = 'Camila' and Client.id_client = 2)

insert into Contenir (id_commande, id_article, Quantite)
select Commande.id_commande, Article.id_article, 20
from Commande, Article
where (Commande.reference = 'Salade5' and Article.nom = 'Cleantopefon' and Article.nature = 'Tools' and Article.couleur = 'DarkPink')

update Commande 
set prix_HT = (select (Contenir.Quantite*Article.prix_HT) as michel from Contenir, Article, Commande where Contenir.id_article = Article.id_article and Contenir.id_commande = Commande.id_commande and Commande.reference = 'Salade5' and Article.nom = 'Cleantopefon' and Article.nature = 'Tools' and Article.couleur = 'DarkPink')
where Commande.reference ='Salade5'

update Commande 
set Prix_TTC = ( select (Commande.prix_HT + Commande.prix_HT*Article.TVA) as jackie from Commande, Article, Contenir where Contenir.id_commande = Commande.id_commande and Contenir.id_article = Article.id_article and Commande.reference = 'Salade5' and Article.nom = 'Cleantopefon' and Article.nature = 'Tools' and Article.couleur = 'DarkPink'),
TVA = (select Article.TVA from Article, Contenir, Commande where Contenir.id_commande = Commande.id_commande and Contenir.id_article = Article.id_article and Commande.reference = 'Salade5' and Article.nom = 'Cleantopefon' and Article.nature = 'Tools' and Article.couleur = 'DarkPink')
where Commande.reference ='Salade5'
update Commande 
set prix_final = (select (prix_TTC + (prix_TTC*remise)/100) from Commande where Commande.reference = 'Salade5')
where Commande.reference ='Salade5'

Insert into Paiement (solde, date_emission, date_paiement, moyen, id_commande)
select 12365, Commande.date_emission, 1995-01-25, 'carte banc', Commande.id_commande
from Commande
where (Commande.reference = 'Salade5')

Afficher une commande

USE LAVRAI_DB_test

SELECT Commande.reference, Commande.date_livraison, Commande.date_emission, Article.nom, Contenir.Quantite, Commande.prix_HT, Commande.prix_TTC, Commande.TVA, Commande.remise, Commande.prix_final
FROM Commande
INNER JOIN Contenir ON Commande.id_commande = Contenir.id_commande
INNER JOIN Article ON Contenir.id_article = Article.id_article
INNER JOIN Client ON Commande.id_client = Client.id_client

WHERE (Client.id_client = 5 AND Client.nom = 'DR. XXXXXX' AND Client.prenom = 'douze')
	vérifié

Suppresion commande

DELETE FROM Contenir WHERE Contenir.id_commande IN(SELECT Commande.id_commande FROM Commande WHERE Commande.id_commande = 3  AND Commande.reference = '0')

DELETE FROM Paiement WHERE Paiement.id_commande IN(SELECT Commande.id_commande FROM Commande WHERE Commande.id_commande = 3  AND Commande.reference = '0')

DELETE FROM Commande WHERE (Commande.id_commande = 3  AND Commande.reference = '0');



Modification commande

UPDATE Commande
SET Commande.date_livraison = 2020-10-02, Commande.date_emission = 2020-10-02, Commande.prix_HT = 15, Commande.prix_TTC = 12, Commande.TVA = 5, Commande.remise = 20, Commande.prix_final = (SELECT Contenir.Quantite*(SELECT Article.prix_HT*Article. FROM Contenir)
FROM Article
WHERE (Article.id_article = 2 AND Article.nom = 'Cleantopefon' AND Article.nature = 'Tools' AND Article.couleur = 'DarkPink  ')

UPDATE Paiement
SET Paiement.solde = 15, Paiement.date_emission = 2020-10-02, Paiement.date_paiement = 2020-10-02, Paiement.moyen = 'LA CB'
FROM Paiement
WHERE (SELECT Commande.reference FROM Commande WHERE Commande.reference = 'Starf' AND Paiement.id_commande = 2 AND Paiement.id_commande IN(SELECT Commande.reference FROM Commande)

UPDATE Contenir
SET Contenir.Quantite = 1
FROM Contenir
WHERE (Contenir.id_commande = 2 AND Contenir.id_commande IN(SELECT Commande.reference FROM Commande)



ARTICLE

Ajout article

USE LAVRAI_DB_test

INSERT INTO Article(nom, nature, prix_HT, quantite_stock, seuil_reapprovisionnement, TVA, couleur) 
Values ('GTX10E15', 'LACARTE', 10, 10, 2, 20, 'vert-kaki'); 


Suppression article

USE LAVRAI_DB_test

DELETE FROM Contenir WHERE Contenir.id_article IN(SELECT  Article.id_article FROM Article WHERE Article.id_article = 14 AND Article.nom = 'Readtaerer' AND Article.nature = 'Furniture' AND Article.couleur = 'BlanchedAl')

DELETE FROM Article WHERE (Article.id_article = 14 AND Article.nom = 'Readtaerer' AND Article.nature = 'Furniture' AND Article.couleur = 'BlanchedAl')


Modifier Article

USE LAVRAI_DB_test

UPDATE Article
SET Article.nom = 'quarante douze', Article.nature = 'laNATU', Article.prix_HT = 15, Article.quantite_stock = 12, Article.seuil_reapprovisionnement = 5, Article.TVA = 20, Article.couleur = 'gris entra'
FROM Article
WHERE (Article.id_article = 2 AND Article.nom = 'Cleantopefon' AND Article.nature = 'Tools' AND Article.couleur = 'DarkPink  ')




Afficher Article

USE LAVRAI_DB_test

SELECT nom, nature, prix_HT, quantite_stock, seuil_reapprovisionnement, TVA, couleur FROM Article WHERE (Article.nom = 'Stereolifiridge' OR Article.nature = '')


Statistiques 

Calculer le panier moyen après la remise :

USE LAVRAI_DB_test ;
SELECT SUM(prix_final)/max(id_commande) AS Prix_moyen_panier FROM Commande;
-- > SELECT SUM(prix_TTC-remise)/max(id_commande) AS Panier_moyen FROM Commande;
	vérifié


Calculer le chiffre d'affaire sur un mois en particulier

USE LAVRAI_DB_test
SELECT SUM(Quantite * solde) AS Chiffre_affaire_sur_un_mois FROM Paiement, Contenir WHERE(month(date_paiement) = 09)
	vérifié


Afficher le nom des articles sous le seuil de réapprovisionnement

"USE DB_test; SELECT Article.nom WHERE (Article.quantite_stock < Article.seuil);";
-- >USE LAVRAI_DB_test; 
SELECT Article.nom AS A_reapprovisionner FROM Article WHERE (Article.quantite_stock < Article.seuil_reapprovisionnement)
	vérifié

Afficher le montant total des achats d'un client

USE LAVRAI_DB_test

SELECT Client.nom, Client.prenom, SUM(Commande.prix_final) AS Montant_des_achats
FROM Client
FULL JOIN Commande ON Client.id_client = Commande.id_client
WHERE (Client.id_client = 1 AND Client.nom = 'DR. XXXXXX' AND Client.prenom = 'douze')
GROUP BY Client.id_client, Client.nom, Client.prenom

Identifier les 10 articles les + vendus

USE LAVRAI_DB_test; 

SELECT TOP 10 Article.nom Articles_les_plus_vendus, SUM(Quantite) Qte

FROM Article
INNER JOIN Contenir ON Article.id_article = Contenir.id_article
GROUP BY Article.nom 
ORDER BY Qte DESC

Identifier les 10 articles les - vendus

USE LAVRAI_DB_test; 

SELECT TOP 10 Article.nom Articles_les_moins_vendus, SUM(Quantite) Qte

FROM Article
INNER JOIN Contenir ON Article.id_article = Contenir.id_article
GROUP BY Article.nom 
ORDER BY Qte ASC


Calculer la valeur d'achat du stock

USE LAVRAI_DB_test; 

SELECT SUM(quantite_stock * prix_HT) AS Valeur_achat_du_stock FROM Article


Calculer la valeur commercial du stock

USE LAVRAI_DB_test; 

SELECT SUM(quantite_stock * (((TVA*prix_HT)/100)+prix_HT)) AS Valeur_commerciale_du_stock FROM Article
