/*----------------------------------------------------------------------------*\
Eigen est une librairie open source qui contient plein plein plein de fonctions 
de base pour faire du calcul scientifique en C++.
lien: http://eigen.tuxfamily.org/index.php?title=Main_Page
Nous en utiliserons qu'une toute petite partie aujourd'hui. Nous utiliserons son
implémentation des vecteurs au sens mathématique : vecteur de R^d.
Les exemples ci-dessous regorupent la plupart des fonctions dont vous aurez 
besoin durant ce TP.
\*----------------------------------------------------------------------------*/

#include <iostream>
#include <Eigen/Dense>  // inclue toute la librairie Eigen


int main(int argc, char* argv[]) {
  // Constructeur.
  //--------------------------------------------------------------------------//
  // Syntaxe Eigen:
  //   Vector<dimension><type> 
  //   dimension peut etre 2, 3 ou 4
  //   type peut etre i (pour integer), f (pour float), d (pour double)
  //   Ainsi, un Vector3f est un vecteur en diomension 3 composé de float.
  Eigen::Vector3f vec_0(0.0, 1.8, 6.7);
  Eigen::Vector3f vec_1(2.0, 1.2, 3.0);

  // Exemple : acceder aux elements d'un vecteur
  //--------------------------------------------------------------------------//
  // On accede aux elements d'un vecteur d'Eigen comme on accede aux elements 
  // d'un tableau via l'operateur []
  std::cout << "vec_0 contient: " << std::endl;   
  std::cout << vec_0[0] << std::endl;
  std::cout << vec_0[1] << std::endl;
  std::cout << vec_0[2] << std::endl;
  std::cout << std::endl;
  
  // Exemple: affichage des deux vecteurs
  //--------------------------------------------------------------------------//
  // rq : on appele la fonction transpose pour obtenir un vecteur ligne
  // (pratique pour l'affichage) par defaut, les vecteurs d'Eigen sont
  // des vecteurs colonne.  
  std::cout << "vec_0: " << vec_0.transpose() << std::endl;
  std::cout << "vec_1: " << vec_1.transpose() << std::endl;
  std::cout << std::endl;

  // Exemple: multiplication par un scalaire
  //--------------------------------------------------------------------------//
  Eigen::Vector3f vec_2 = 2.0 * vec_0;
  std::cout << "2.0*vec_0: " << vec_2.transpose() << std::endl; 
  std::cout << std::endl;

  // Exemple: produit scalaire
  //--------------------------------------------------------------------------//
  float dot_prod = vec_0.dot(vec_1);
  std::cout << "<vec_0,vec_1>: " << dot_prod << std::endl;  
  std::cout << std::endl;

  // Exemple: produit vectoriel
  //--------------------------------------------------------------------------//
  Eigen::Vector3f vec_3 = vec_0.cross(vec_1);
  std::cout << "vec_0*vec_1: " << vec_3.transpose() << std::endl; 
  std::cout << std::endl;
}
