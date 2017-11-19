#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int randEntreBornes(int a, int b);//Prototype de la fonction de generation de nb aleatoires

int main()
{
    int vie = 100;
    int entreClavier = 0;
    int nombreAleatoire = 0;
    int nombrePotions = 5;
    int distance = 0;
    int distanceParcourue = 0;
    int rentreDansLeau = 0;
    int RencLeviator = 0; //rencontre avec leviator dans le lac
    int battreLeviator = 0 ;
    int entreClavier2 = 0;
    int rencCascade = 0; //rencontre avec une cascade

    srand(time(NULL)); // initialisation de rand avec l'heure courante comme seed pour ne pas avoir toujours la même séquence de nombres aléatoires

    cout << "Quel est ton nom aventurier ?" << endl;
    string nomAventurier("Aventurier sans nom");
	cin >> nomAventurier;
    cout << "Ah, vous etes le celebre " << nomAventurier <<  endl;

    while(vie > 0)
    {
		cout << "Que veux tu faire ?" << endl << "(1) pour avancer / (2) pour boire une potion" << endl;
		cin >> entreClavier;
		cout << endl;
		if (entreClavier == 1)
		{
			rentreDansLeau = randEntreBornes(1,100) ;
			if (rentreDansLeau >= 95)
            {
                cout << "tu rentre dans un lac" << endl;
                cout << "tu prend un kayak" << endl << endl;
                RencLeviator = randEntreBornes(1,10);
                if (RencLeviator >= 5)
                {
                    cout << "tu rencontre leviator" << endl << endl;
                    cout << "veut tu combatre ?" << "si oui taper 1 si non taper 2" << endl << endl;
                    cin >> entreClavier2;
                    if (entreClavier2 == 1)
                    {
                       battreLeviator = randEntreBornes(1,10);
                        if (battreLeviator  >= 5)
                        {
                            cout << "bravo tu as battue leviator et tu sors du lac" << endl << endl;
                            cout << "tu gagne une potion" << endl << endl;
                            nombrePotions ++ ;
                            cout << "Tu as maintenant " << nombrePotions << " potions." <<endl << endl;
                        }
                        else
                        {
                            cout << "leviator t'a battue et t'a fait quelque domage" << endl << endl;
                            cout << "Mais tu sors tout de meme du lac" << endl << endl;
                            vie = vie - randEntreBornes(20,30);
                            cout << "Tu as " << vie << "points de vie." <<endl << endl;
                        }
                    }
                    else if (entreClavier2 == 2)
                    {
                        rencCascade = randEntreBornes(1,100);
                        if (rencCascade >=50)
                        {
                            cout << "en fuyant tu rencontre une cascade et tu perd de la vie" << endl << endl ;
                            vie = vie - randEntreBornes(10,20);
                            cout << "tu sort quand meme du lac" << endl << endl ;
                            cout << "Tu as " << vie << "points de vie." <<endl << endl;
                        }
                        else
                        {
                            cout << "tu fuis et tu sort du lac" << endl << endl;
                        }

                    }
                    else
                    {
                        cout << "tu dois choissir entre 1 et 2 rien d'autre donc rien ne ce passe" << endl << endl;
                    }

                }
            }
			else
            {


                cout << "Tu avance dans une foret sombre ..." << endl << endl ;
                nombreAleatoire = randEntreBornes(1,6);
                distance = rand() % 10 + 10;
                distanceParcourue = distanceParcourue+distance;
                if(nombreAleatoire > 4)
                {
                    nombrePotions++;
                    cout << "Yes tu as trouve une potion. Tu as maintenant " << nombrePotions << " potions." << endl << endl << "Tu as parcouru "<< distanceParcourue << " m " << endl << endl;
                }
                else if (nombreAleatoire > 2)
                {
                    cout << "Aie tu as rencontre un monstre." << endl << endl <<"Tu as parcouru "<< distanceParcourue << " m " << endl << endl ;
                    vie = vie - randEntreBornes(8,15);
                    cout << "Tu as " << vie << "points de vie." <<endl;
                }
                else
                {
				cout << "Il ne se passe rien" << endl << endl <<"Tu as parcouru "<< distanceParcourue << " m " << endl << endl ;
                }
            }
		}
		else if (entreClavier == 2)
		{
			if (nombrePotions > 0)
			{
			cout << "Tu te sens tout de suite mieux !" << endl << endl;
			vie += 10;
			nombrePotions--;
			cout << "Attention, il ne te reste que " << nombrePotions << " potions." << endl << endl;
			cout << "Tu as " << vie << "points de vie." <<endl;
			}
			else
			{
				cout << "Domage, tu n'as plus de potions en reserve." << endl << endl;
			}
		}
		else
        {
            cout << "Choisis un nombre entre 1 et 2 !" << endl << endl;
        }
	}

	cout << "Tu es mort aventurier !" << endl;

    return 0;
}



// On suppose a<b
int randEntreBornes(int a, int b)
{
    return rand()%(b-a) +a;
}
