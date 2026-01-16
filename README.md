# BE_POO_Bin_Inventory

Projet d'inventaire électronique en C++ utilisant la programmation orientée objet (POO).

## Description

Ce projet vise à créer une application d'inventaire électronique en C++ en utilisant les principes de la programmation orientée objet. 
L'application permettra de gérer un inventaire de d'items : 

Lorsqu'on pose une bin/boite sur la matrice de capteurs, l'application détecte la présence de la bin et demande à l'utilisateur son contenu pour l'enregistrer dans une base de données (ici une liste chainée).

Lorsqu'on retire une bin/boite de la matrice de capteurs, l'application détecte son absence et supprime l'item correspondant dans la base de données.

Via le moniteur série, l'utilisateur peut afficher l'inventaire actuel.
Il a deux actions possibles :
- Modifier la quantité d'un item
- Faire resortir un item visuellement (allumage LED)

## Fonctionnalités 

- Détection de la présence/absence de bins sur une matrice de capteurs
- Enregistrement des items dans une base de données (liste chainée)
- Affichage de l'inventaire actuel via le moniteur série
- Modification de la quantité d'un item
- Allumage LED pour faire ressortir un item visuellement

## Technologies Utilisées

- C++
- Programmation Orientée Objet (POO)
- Liste chainée pour la gestion de la base de données
- Matrice de capteurs pour la détection des bins
- Moniteur série pour l'interaction utilisateur
- LED pour l'indication visuelle des items

