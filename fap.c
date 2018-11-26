#include "fap.h"
#include <unistd.h>
#include <stdlib.h>

// bla bla 

fap creer_fap_vide(int (*comparaison)(int, int))
{
  fap resultat;

  resultat.tete = NULL;
  resultat.fctComparaison = comparaison;
  return resultat;
}

fap inserer(fap f, int element, int priorite)
{
  struct maillon *nouveau, *courant, *precedent;

  nouveau = (struct maillon *) malloc(sizeof(struct maillon));
  nouveau->element = element;
  nouveau->priorite = priorite;
  if ((f.tete == NULL) || f.fctComparaison(priorite,f.tete->priorite))
    {
      nouveau->prochain = f.tete;
      f.tete = nouveau;
    }
  else
    {
      precedent = f.tete;
      courant = precedent->prochain;
      while ((courant != NULL) && !f.fctComparaison(priorite,courant->priorite))
        {
          precedent = courant;
          courant = courant->prochain;
        }
      precedent->prochain = nouveau;
      nouveau->prochain = courant;
    }
  return f;
}

fap extraire(fap f, int *element, int *priorite)
{
  struct maillon *courant;

  if (f.tete != NULL)
    {
      courant = f.tete;
      *element = courant->element;
      *priorite = courant->priorite;
      f.tete = courant->prochain;
      free(courant);
    }
  return f;
}

int est_fap_vide(fap f)
{
  return f.tete == NULL;
}

void
detruire_fap(fap f)
{
  int element, priorite;

  while (!est_fap_vide(f))
      f = extraire(f,&element,&priorite);
}
