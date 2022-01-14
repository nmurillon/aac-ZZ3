# ZZ3 - Algorithmique avancée et complexité

Travail de Slimane FAKANI et Nicolas MURILLON

## Algorithmes choisis

Lors de cours, nous avons choisi de développer les algorithmes suivants en c++ :

  - Calcul d'une enveloppe convexe
  - Triangulation de Delaunay
  - Exponentiation rapide
  - Résolution de systèmes d'équations linéaires
  - Trouver le plus grand rectangle dans un Histogramme

## Calcul d'une enveloppe convexe

Étant donné un ensemble fini de points dans un espace à 2 dimensions, l'objectif est de trouver l'enveloppe convexe de cet ensemble.

L'enveloppe convexe d'un objet ou d'un regroupement d'objets géométriques est l'ensemble convexe le plus petit parmi ceux qui le contiennent.

Dans un plan, l'enveloppe convexe peut être comparée à la région limitée par un élastique qui englobe tous les points qu'on relâche jusqu'à ce qu'il se contracte au maximum. [Définition de wikipédia](https://fr.wikipedia.org/wiki/Enveloppe_convexe)

Pour qu'un ensemble fini de points possède une enveloppe convexe, ce dernier doit posséder au moins 3 points.

Pour calculer l'enveloppe convexe, nous allons utiliser l'algorithme `Marche de Jarvis`. 

Le principe de cet algorithme est très simple : on part du points d'abscisse minimale dans notre ensemble de points. Ensuite on cherche le point d'angle polaire minimale par rapport à ce point, parmis les points restants.

On itère ensuite jusqu'à revenir au point de départ.

Les premières itérations peuvent être illustées par la figure suivante :

![Illustration des premières itérations de la marche de Jarvis](https://upload.wikimedia.org/wikipedia/commons/thumb/d/de/Jarvis_march_convex_hull_algorithm_diagram.svg/220px-Jarvis_march_convex_hull_algorithm_diagram.svg.png)

## Triangulation de Delaunay

## Exponentiation rapide

## Résolution de systèmes d'équations linéaires

## Trouver le plus grand rectangle dans un histogramme
