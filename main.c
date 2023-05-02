/**--------------------------------------------------------**/
/**       C o n v e r s i o n   Z vers C (Standard)        **/
/**             Realisee par Pr D.E ZEGOUR                 **/
/**             E S I - Alger                              **/
/**             Copywrite 2014                             **/
/**--------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define True 1
#define False 0

/** Implementation **\: ARBRE BINAIRE DE STRUCTURES**/

/** Structures statiques **/

typedef struct Tib Type_Tib  ;
typedef Type_Tib * Typestr_Tib ;
typedef int Type1_Tib  ;
typedef bool Type2_Tib  ;
struct Tib
{
    Type1_Tib Champ1 ;
    Type2_Tib Champ2 ;
};

Type1_Tib Struct1_Tib ( Typestr_Tib S)
{
    return  S->Champ1 ;
}

Type2_Tib Struct2_Tib ( Typestr_Tib S)
{
    return  S->Champ2 ;
}

void Aff_struct1_Tib ( Typestr_Tib S, Type1_Tib Val )
{
    S->Champ1 = Val ;
}

void Aff_struct2_Tib ( Typestr_Tib S, Type2_Tib Val )
{
    S->Champ2 = Val ;
}


/** Arbres de recherche binaire **/

typedef Typestr_Tib Typeelem_ATib   ;
typedef struct Noeud_ATib * Pointeur_ATib ;

struct Noeud_ATib
{
    Typeelem_ATib  Val ;
    Pointeur_ATib Fg ;
    Pointeur_ATib Fd ;
    Pointeur_ATib Pere ;
} ;

Typeelem_ATib Info_ATib( Pointeur_ATib P )
{
    return P->Val;
}

Pointeur_ATib Fg_ATib( Pointeur_ATib P)
{
    return P->Fg ;
}

Pointeur_ATib Fd_ATib( Pointeur_ATib P)
{
    return P->Fd ;
}

Pointeur_ATib Pere_ATib( Pointeur_ATib P)
{
    return P->Pere ;
}

void Aff_Info_ATib ( Pointeur_ATib P, Typeelem_ATib Val)
{
    Typeelem_ATib _Temp ;
    _Temp = malloc(sizeof(Type_Tib));
    /* Affectation globale de structure */
    _Temp->Champ1 = Val->Champ1;
    _Temp->Champ2 = Val->Champ2;
    Val = _Temp ;
    P->Val = Val ;
}

void Aff_fg_ATib( Pointeur_ATib P, Pointeur_ATib Q)
{
    P->Fg =  Q;
}

void Aff_fd_ATib( Pointeur_ATib P, Pointeur_ATib Q)
{
    P->Fd =  Q ;
}

void Aff_pere_ATib( Pointeur_ATib P, Pointeur_ATib Q)
{
    P->Pere =  Q ;
}

void Creernoeud_ATib( Pointeur_ATib *P)
{
    *P = (struct Noeud_ATib *) malloc( sizeof( struct Noeud_ATib))   ;
    (*P)->Val = malloc(sizeof(Type_Tib));
    (*P)->Fg = NULL;
    (*P)->Fd = NULL;
    (*P)->Pere = NULL;
}

void Liberernoeud_ATib( Pointeur_ATib P)
{
    free( P ) ;
}


/** Variables du programme principal **/
Pointeur_ATib Racine=NULL;
Pointeur_ATib P1=NULL;
Pointeur_ATib P2=NULL;
Pointeur_ATib P3=NULL;
Pointeur_ATib P4=NULL;
int K;
int I;
int Choix;
bool choix2=false;
int nbNil;

/** Fonctions standards **/

int Aleanombre( int N )
{
    return ( rand() % N );
}


/** Prototypes des fonctions **/

void Creer (Pointeur_ATib *Racine, int *K);
void Inordre (Pointeur_ATib *Racine);
Pointeur_ATib Rotation_gauche (Pointeur_ATib *R) ;
Pointeur_ATib Rotation_droite (Pointeur_ATib *R) ;
void Liste_d_crois (Pointeur_ATib *R);
void Affich_list_d_crois (Pointeur_ATib *R);
void Liste_g_decr (Pointeur_ATib *R);
void Affich_l_g_decrois (Pointeur_ATib *R);
int  Nbnoeuds (Pointeur_ATib *R) ;
void Transf_g_suite (Pointeur_ATib *R, int *K);
void Transf_d_suite (Pointeur_ATib *R, int *K);
void Transf_d_aleatoire (Pointeur_ATib *R);
void Transf_g_aleatoire (Pointeur_ATib *R);
void Transf_alea_ident (Pointeur_ATib *R);
void Affich_arbre_trans (Pointeur_ATib *R);

/**---------------------------------------------------------------------------------**/
void Creer (Pointeur_ATib *Racine,int *K)
{
    /** Variables locales **/
    Pointeur_ATib Racined;
    Pointeur_ATib Racineg;
    Pointeur_ATib P=NULL;
    Pointeur_ATib Q;
    Pointeur_ATib New=NULL;
    Typestr_Tib Noeud;
    int N;
    int Ng;
    int Nd;

    /** Corps du module **/
    Noeud = malloc(sizeof(Type_Tib));
     N  = *K;
    Nd  =  N/2;
    Ng  =  N - Nd ;
    Aff_struct1_Tib ( Noeud, 1000 ) ;
    Aff_struct2_Tib ( Noeud, False ) ;
    Creernoeud_ATib (& *Racine ) ;
    Racineg=NULL;
    Racined=NULL;
    Aff_Info_ATib ( *Racine, Noeud ) ;
    for( I  =  1 ; I <=  Ng ; ++I)
    {
        Aff_struct1_Tib ( Noeud, Aleanombre(1000 ) ) ;
        Aff_struct2_Tib ( Noeud, False ) ;
        Creernoeud_ATib (& New ) ;
        Aff_Info_ATib ( New, Noeud ) ;

        if( Racineg == NULL)
        {
            Racineg  =  New ;
        }
        else
        {
            P  =  Racineg ;
            Q=P;
            while( P != NULL && Q!=NULL)
            {
                Q  =  P ;
                if( Struct1_Tib ( Info_ATib ( New )  ) < Struct1_Tib ( Info_ATib ( P )  ))
                {
                    P  =  Fg_ATib ( P );
                }
                else
                {
                    if ( Struct1_Tib ( Info_ATib ( New )  ) > Struct1_Tib ( Info_ATib ( P )  ))
                    P  =  Fd_ATib ( P ) ;
                    else
                        Q=NULL;

                } ;

            } ;
            if (Q!=NULL)
            {

            if( ( Struct1_Tib ( Info_ATib ( New )  ) < Struct1_Tib ( Info_ATib ( Q )  ) ))
            {
                Aff_fg_ATib ( Q, New ) ;

            } ;
            if( ( Struct1_Tib ( Info_ATib ( New )  ) > Struct1_Tib ( Info_ATib ( Q )  ) ))
            {
                Aff_fd_ATib ( Q, New ) ;

            } ;
            }
            else
            {


                Liberernoeud_ATib ( New ) ;
                Ng  =  Ng + 1 ;
            }
            } ;

        } ;

    for( I  =  1 ; I <=  Nd ; ++I)
    {
        Aff_struct1_Tib ( Noeud, Aleanombre(1000 ) ) ;
        Aff_struct2_Tib ( Noeud, True ) ;
        Creernoeud_ATib (& New ) ;
        Aff_Info_ATib ( New, Noeud ) ;
        if( Racined == NULL)
        {
            Racined  =  New ;
        }
        else
        {
            P  =  Racined ;
            Q=P;
            while( P != NULL && Q!=NULL)
            {
                Q  =  P ;
                if( Struct1_Tib ( Info_ATib ( New )  ) < Struct1_Tib ( Info_ATib ( P )  ))
                {
                    P  =  Fg_ATib ( P );
                }
                 else
                {
                    if ( Struct1_Tib ( Info_ATib ( New )  ) > Struct1_Tib ( Info_ATib ( P )  ))
                    P  =  Fd_ATib ( P ) ;
                    else
                        Q=NULL;

                } ;

            } ;
            if (Q!=NULL)
            {

            if( ( Struct1_Tib ( Info_ATib ( New )  ) < Struct1_Tib ( Info_ATib ( Q )  ) ))
            {
                Aff_fg_ATib ( Q, New ) ;

            } ;
            if( ( Struct1_Tib ( Info_ATib ( New )  ) > Struct1_Tib ( Info_ATib ( Q )  ) ))
            {
                Aff_fd_ATib ( Q, New ) ;

            } ;
            }
            else
            {


                Liberernoeud_ATib ( New ) ;
                Nd  =  Nd + 1 ;
            }
            } ;

        } ;
    Aff_fg_ATib ( *Racine, Racineg ) ;
    Aff_fd_ATib ( *Racine, Racined ) ;
    printf ( " %s", "------- Arbre Cree!  -------- \n " ) ;

}
/**-------------------------------------------------------------------------------------------**/
void Inordre (Pointeur_ATib *Racine)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib _Px1;
    Pointeur_ATib _Px2;

    /** Corps du module **/
    P  =  *Racine ;
    if( ( P != NULL ))
    {
        _Px1 =  Fg_ATib ( P ) ;
        Inordre ( &_Px1) ;
        printf ( " %d | ", Struct1_Tib(Info_ATib(P)) ) ;
        _Px2 =  Fd_ATib ( P ) ;
        Inordre ( &_Px2) ;

    } ;

}
/**-------------------------------------------------------------------------------------------**/
Pointeur_ATib Rotation_gauche (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib Rotation_gauche2 ;
    Pointeur_ATib P;
    Pointeur_ATib Tmp;

    /** Corps du module **/
    P  =  *R ;
    Tmp  =  Fd_ATib ( P ) ;
    if( ( Tmp != NULL ))
    {
        Aff_fd_ATib ( P, Fg_ATib ( Tmp ) ) ;
        Aff_fg_ATib ( Tmp, P ) ;

    } ;
    Rotation_gauche2  =  Tmp ;

    return Rotation_gauche2 ;
}
/**-------------------------------------------------------------------------------------------**/
Pointeur_ATib Rotation_droite (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib Rotation_droite2 ;
    Pointeur_ATib Tmp;

    /** Corps du module **/
    Tmp  =  Fg_ATib ( *R ) ;
    if( ( Tmp != NULL ))
    {
        Aff_fg_ATib ( *R, Fd_ATib ( Tmp ) ) ;
        Aff_fd_ATib ( Tmp, *R ) ;

    } ;
    Rotation_droite2  =  Tmp ;

    return Rotation_droite2 ;
}
/**--------------------------------------------------------------------------------------------**/
void Liste_d_crois (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib Sauv;

    /** Corps du module **/
    Sauv  =  *R ;
    P  =  *R ;
    *R  =  Fd_ATib ( *R ) ;
    while( ( *R != NULL ))
    {
        while( ( Fg_ATib ( *R ) != NULL ))
        {
            *R  =  Rotation_droite ( & *R ) ;
            Aff_fd_ATib ( P, *R ) ;

        } ;
        P  =  *R ;
        *R  =  Fd_ATib ( *R ) ;

    } ;
    *R  =  Sauv ;

}
/**----------------------------------------------------------------------------------------------**/
void Affich_list_d_crois (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib P;

    /** Corps du module **/
    printf ( " %s", "\n\n\n\t\t ------- Liste droite croissante  -------- \n\n\t " ) ;
    P  =  Fd_ATib ( *R ) ;
    while( ( P != NULL ))
    {
        printf ( " %d -", Struct1_Tib(Info_ATib(P)) ) ;
        P  =  Fd_ATib ( P ) ;

    } ;

}
/**---------------------------------------------------------------------------------------------**/
void Liste_g_decr (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib Sauv;

    /** Corps du module **/
    Sauv  =  *R ;
    P  =  *R ;
    *R  =  Fg_ATib ( *R ) ;
    while( ( *R != NULL ))
    {
        while( ( Fd_ATib ( *R ) != NULL ))
        {
            *R  =  Rotation_gauche ( & *R ) ;
            Aff_fg_ATib ( P, *R ) ;

        } ;
        P  =  *R ;
        *R  =  Fg_ATib ( *R ) ;

    } ;
    *R  =  Sauv ;

}
/**---------------------------------------------------------------------------------------------**/
void Affich_l_g_decrois (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib P;

    /** Corps du module **/
    printf ( " %s", "\n\n\n\t\t ------- Liste gauche decroissante  -------- \n\n\t " ) ;
    P  =  Fg_ATib ( *R ) ;
    while( ( P != NULL ))
    {
        printf ( " %d -", Struct1_Tib(Info_ATib(P)) ) ;
        P  =  Fg_ATib ( P ) ;

    } ;

}
/**--------------------------------------------------------------------------------------------------------**/
int  Nbnoeuds (Pointeur_ATib *R)
{
    /** Variables locales **/
    int  Nbnoeuds2 ;
    Pointeur_ATib _Px1;
    Pointeur_ATib _Px2;

    /** Corps du module **/
    if( ( *R == NULL ))
    {
        Nbnoeuds2  =  0 ;
    }
    else
    {
        _Px1 =  Fg_ATib ( *R ) ;
        _Px2 =  Fd_ATib ( *R ) ;
        Nbnoeuds2  =  ( 1 + Nbnoeuds ( &_Px1) + Nbnoeuds ( &_Px2) ) ;

    }
    return Nbnoeuds2 ;
}
/**--------------------------------------------------------------------------------------------------------**/
void Transf_g_suite (Pointeur_ATib *R, int *K)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib Sauv;
    int N;
    Pointeur_ATib _Px1;

    /** Corps du module **/
    Sauv  =  *R ;
    P  =  *R ;
    *R  =  Fg_ATib ( *R ) ;
    N  =  *K ;
    while( ( *R != NULL ))
    {
        _Px1 =  Fd_ATib ( *R ) ;
        if( ( Nbnoeuds ( &_Px1) < N ))
        {
            *R  =  Rotation_droite ( & *R ) ;
            if( ( *R != NULL ))
            {
                Aff_fg_ATib ( P, *R ) ;

            }
        }
        else
        {
            P  =  *R ;
            *R  =  Fg_ATib ( *R ) ;
            N  =  N + *K ;

        }
    } ;
    *R  =  Sauv ;

}
/**--------------------------------------------------------------------------------------------------------**/
void Transf_d_suite (Pointeur_ATib *R, int *K)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib Sauv;
    int N;
    Pointeur_ATib _Px1;

    /** Corps du module **/
    Sauv  =  *R ;
    P  =  *R ;
    *R  =  Fd_ATib ( *R ) ;
    N  =  *K ;
    while( ( *R != NULL ))
    {
        _Px1 =  Fg_ATib ( *R ) ;
        if( ( Nbnoeuds ( &_Px1) < N ))
        {
            *R  =  Rotation_gauche ( & *R ) ;
            if( ( *R != NULL ))
            {
                Aff_fd_ATib ( P, *R ) ;

            }
        }
        else
        {
            P  =  *R ;
            *R  =  Fd_ATib ( *R ) ;
            N  =  N + *K ;

        } ;

    } ;
    *R  =  Sauv ;

}
/**--------------------------------------------------------------------------------------------------------**/
void Transf_d_aleatoire (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib Sauv;
    int K;
    int N;
    Pointeur_ATib _Px1;

    /** Corps du module **/
    Sauv  =  *R ;
    P  =  *R ;
    *R  =  Fd_ATib ( *R ) ;
    N  =  Aleanombre(2)+3 ;
    while( ( *R != NULL ))
    {
        _Px1 =  Fg_ATib ( *R ) ;
        if( ( Nbnoeuds ( &_Px1) < N ))
        {
            *R  =  Rotation_gauche ( & *R ) ;
            if( ( *R != NULL ))
            {
                Aff_fd_ATib ( P, *R ) ;

            }
        }
        else
        {
            P  =  *R ;
            *R  =  Fd_ATib ( *R ) ;
            N  =  Aleanombre(2)+3 ;

        } ;

    } ;
    *R  =  Sauv ;

}
/**--------------------------------------------------------------------------------------------------------**/
void Transf_g_aleatoire (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib P;
    Pointeur_ATib Sauv;
    int K;
    int N;
    Pointeur_ATib _Px1;

    /** Corps du module **/
    Sauv  =  *R ;
    P  =  *R ;
    *R  =  Fg_ATib ( *R ) ;
    N  =  Aleanombre(2)+1 ;
    while( ( *R != NULL ))
    {
        _Px1 =  Fd_ATib ( *R ) ;
        if( ( Nbnoeuds ( &_Px1) < N ))
        {
            *R  =  Rotation_droite ( & *R ) ;
            if( ( *R != NULL ))
            {
                Aff_fg_ATib ( P, *R ) ;

            }
        }
        else
        {
            P  =  *R ;
            *R  =  Fg_ATib ( *R ) ;
            N  =  Aleanombre(2) + 1 ;

        } ;

    } ;
    *R  =  Sauv ;

}
/**--------------------------------------------------------------------------------------------------------**/
void Transf_alea_ident (Pointeur_ATib *R)
{
    /** Variables locales **/
    int N;
    int SAUV;
    bool stop1=false;
    bool stop2=false;
    Pointeur_ATib P_gauche;
    Pointeur_ATib P_droit;
    Pointeur_ATib R_gauche;
    Pointeur_ATib R_droit;
    Pointeur_ATib Sauv;
    Pointeur_ATib _Px1;
    Pointeur_ATib _Px2;

    /** Corps du module **/
    Sauv  =  *R ;
    P_gauche  =  *R ;
    P_droit  =  *R ;
    R_gauche  =  Fg_ATib ( *R ) ;
    R_droit  =  Fd_ATib ( *R ) ;
    N  =  Aleanombre(4 ) + 1 ;
    while( ( ( R_gauche != NULL ) || ( R_droit != NULL ) ))
    {
        while( ( R_gauche != NULL ) && !stop1)
        {
            _Px1 =  Fd_ATib ( R_gauche ) ;
            if( ( Nbnoeuds ( &_Px1) < N ))
            {
                R_gauche  =  Rotation_droite ( & R_gauche ) ;
                if( ( R_gauche != NULL ))
                {
                    Aff_fg_ATib ( P_gauche, R_gauche ) ;

                }
            }
            else
            {
                P_gauche  =  R_gauche ;
                R_gauche  =  Fg_ATib ( R_gauche ) ;
                stop1=true;
            } ;

        } ;
        while( ( R_droit != NULL ) && !stop2)
        {
            _Px2 =  Fg_ATib ( R_droit ) ;
            if( ( Nbnoeuds ( &_Px2) < N ))
            {
                R_droit  =  Rotation_gauche ( & R_droit ) ;
                if( ( R_droit != NULL ))
                {
                    Aff_fd_ATib ( P_droit, R_droit ) ;

                }
            }
            else
            {
                P_droit  =  R_droit ;
                R_droit  =  Fd_ATib ( R_droit ) ;
                stop2=true;
            } ;

        } ;
        N  =  Aleanombre(4) + 1 ;
        stop1=false;
        stop2=false;

    } ;
    *R  =  Sauv ;

}
/**----------------------------------------------------------------------------------**/
void Affich_arbre_trans (Pointeur_ATib *R)
{
    /** Variables locales **/
    Pointeur_ATib Pg;
    Pointeur_ATib Pd;
    Pointeur_ATib F;
    int N;

    /** Corps du module **/
    N  =  1 ;
    printf ( " %s", "\n\n\t ------- Affichage de l''arbre apres transformation: -------- \n" ) ;
    printf ( " %s", "Racine:  \n" ) ;
    printf ( " %d \n --------------------- \n", Struct1_Tib(Info_ATib(*R)) ) ;
    Pg  =  Fg_ATib ( *R ) ;
    Pd  =  Fd_ATib ( *R ) ;
    while( ( Pg != NULL ) || ( Pd != NULL ))
    {
                printf ( " %s", "Gauche: \n  " ) ;
        F  =  Pg ;
        while( ( F != NULL ))
        {
            printf (" %d -", Struct1_Tib(Info_ATib(F)) ) ;
            F  =  Fd_ATib ( F ) ;

        } ;
        printf ( " %s", "\n ----\n" ) ;
        printf ( " %s", "Droit: \n  " ) ;
        F  =  Pd ;
        while( ( F != NULL ))
        {
            printf ( " %d -", Struct1_Tib(Info_ATib(F)) ) ;
            F  =  Fg_ATib ( F ) ;

        } ;
        printf ( " %s", "\n --------------------- \n" ) ;
        N  =  N + 1 ;
        if( ( Pg != NULL ))
        {
            Pg  =  Fg_ATib ( Pg ) ;

        } ;
        if( ( Pd != NULL ))
        {
            Pd  =  Fd_ATib ( Pd ) ;

        } ;

    } ;

}
//==================================================================================
//==================================================================================
//MODULES RAJOUTES :
//==================================================================================
//==================================================================================

void dessinArbre_droite (Pointeur_ATib R, FILE* f)
{
    if (R != NULL)
    {
        if (Fg_ATib(R) != NULL)
        {
            fprintf(f, "  \"%d\" -> \"%d\" \n", Struct1_Tib(Info_ATib(R)), Struct1_Tib(Info_ATib(Fg_ATib(R))));


        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", nbNil);
            fprintf(f, "  \"%d\" -> \"NIL%d\" ", Struct1_Tib(Info_ATib(R)), nbNil++);
            fprintf(f, " [style=invis];\n");
        }

        fprintf(f, "  \"NIL%d\" [style=invis];\n", nbNil);
        fprintf(f, "  \"%d\" -> \"NIL%d\" ", Struct1_Tib(Info_ATib(R)), nbNil++);
        fprintf(f, " [style=invis];\n");

        if (Fd_ATib(R)!= NULL)
        {
            fprintf(f, "  \"%d\" -> \"%d\" \n", Struct1_Tib(Info_ATib(R)), Struct1_Tib(Info_ATib(Fd_ATib(R))));
        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", nbNil);
            fprintf(f, "  \"%d\" -> \"NIL%d\" ", Struct1_Tib(Info_ATib(R)), nbNil++);
            fprintf(f, " [style=invis];\n");
        }

        dessinArbre_droite(Fg_ATib(R), f);
        dessinArbre_droite(Fd_ATib(R), f);
    }
}
//==================================================================================


void dessinArbre_gauche (Pointeur_ATib R, FILE* f)
{
    if (R != NULL)
    {
        if (Fg_ATib(R) != NULL)
        {
            fprintf(f, "  \"%d\" -> \"%d\" \n", Struct1_Tib(Info_ATib(R)), Struct1_Tib(Info_ATib(Fg_ATib(R))));


        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", nbNil);
            fprintf(f, "  \"%d\" -> \"NIL%d\" ", Struct1_Tib(Info_ATib(R)), nbNil++);
            fprintf(f, " [style=invis];\n");
        }

        fprintf(f, "  \"NIL%d\" [style=invis];\n", nbNil);
        fprintf(f, "  \"%d\" -> \"NIL%d\" ", Struct1_Tib(Info_ATib(R)), nbNil++);
        fprintf(f, " [style=invis];\n");

        if (Fd_ATib(R)!= NULL)
        {
            fprintf(f, "  \"%d\" -> \"%d\" \n", Struct1_Tib(Info_ATib(R)), Struct1_Tib(Info_ATib(Fd_ATib(R))));
        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", nbNil);
            fprintf(f, "  \"%d\" -> \"NIL%d\" ", Struct1_Tib(Info_ATib(R)), nbNil++);
            fprintf(f, " [style=invis];\n");
        }


        dessinArbre_gauche(Fg_ATib(R), f);
        dessinArbre_gauche(Fd_ATib(R), f);
    }
}

//=================================================

void dessin(Pointeur_ATib R)
{
    if (R == NULL)
    {
        printf ("> ERREUR : Arbre vide !");
    }
    else
    {
        FILE *f;
        f = fopen("arbre1.dot","w");
        fprintf(f, "digraph arbre {\n");
        nbNil=0;
        fprintf(f," \"%d\" [ shape=circle,style=filled ,color=black ] \n ",Struct1_Tib(Info_ATib(R)));
        if (Fd_ATib(R)!=NULL)
        {
            fprintf(f,"node [ shape=circle ,style=filled, color=black ] \n ");

            fprintf(f," \"%d\" -> \"%d\" \n ",Struct1_Tib(Info_ATib(R)),Struct1_Tib(Info_ATib(Fg_ATib(R))));
            dessinArbre_gauche(Fg_ATib(R), f );
        }
        if (Fd_ATib(R)!=NULL)
        {
            fprintf(f,"node [ shape=circle ,style =bold , fontcolor=invis ]\n ");

            fprintf(f," \"%d\" -> \"%d\" \n ",Struct1_Tib(Info_ATib(R)),Struct1_Tib(Info_ATib(Fd_ATib(R)) ));
            dessinArbre_droite(Fd_ATib(R),f);

        }

        fprintf(f, "}\n");
        fclose(f);
        system("dot -T png arbre1.dot -o arbre1.png");
        system("mspaint arbre1.png");
    }
}
//==================================================================================
// Procédure qui imprime le splashscreen du TP
void splashscreen(void)
{
    system("COLOR 6");
    printf("\n\n\t  ______  _____ _____ ");
    printf("\n\t |  ____|/ ____|_   _|\t Ecole Nationale");
    printf("\n\t | |__  | (___   | |  ");
    printf("\n\t |  __|  |___ |  | |  \t Sup""\x8A""rieure");
    printf("\n\t | |____ ____) |_| |_ ");
    printf("\n\t |______|_____/|_____|\t d'Informatique");
    printf("\n\n");
    Sleep(300);
    printf("\n\t\t\t\t  _______ _____           ");
    printf("\n\t\t\t\t |__   __|  __  |      _  ");
    printf("\n\t\t\t\t    | |  | |__) |     (_) ");
    printf("\n\t\t\t\t    | |  |  ___/              ** Dessiner des arbres avec des rotations **");
    printf("\n\t\t\t\t    | |  | |           _  ");
    printf("\n\t\t\t\t    |_|  |_|          (_) ");
    printf("\n\t\t\t\t        ");
    Sleep(300);
    printf("\n\n\t\t\t\t     Ann""\x82""e Universitaire 2020-2021 | Sem""\x8A""stre 2 \n\n\t\t");
    Sleep(300);
    system("pause");
    system("cls");
}
//==================================================================================
// Procédure qui imprime la carte des informations du TP
void CarteTP()
{
    system("COLOR 03");
    printf("\n\n\t__________________________________________________________________________________________________\n");
    printf("\t|            ==============================={ BIENVENUE }==============================          |\n");
    printf("\t|                     *****  TP2 : Dessiner des arbres avec des rotations                        |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                             -> R""\x82""alis""\x82"" par:                                                    |\n");
    printf("\t|                                << Samy Ghebache  >>                                            |\n");
    printf("\t|                                << Rayane Djouah >>                                            |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                                 Module  :   ALSDD                                              |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                              Algorithmiques et Structures des Donn""\x82""es Dynamiques               |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                      1 ""\x8A""re ann""\x82""e cycle pr""\x82""paratoire - Groupe 6                                 |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                [ Ecole Nationale Sup""\x8A""rieure d'Informatique (ESI Ex INI) - Alger ]              |\n");
    printf("\t|            =========================================================================           |\n");
    printf("\t|________________________________________________________________________________________________|\n\n\n\t\t");
    system("pause");
    system("cls");

}
//==================================================================================
void merci()
{
    system("cls");
    system("COLOR 6");
    printf("\n\n\n");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                                            *");
    printf("\n\n\t\t\t\t\t     *                    MERCI !                 *");
    printf("\n\n\t\t\t\t\t     *                                            *");
    printf("\n\n\t\t\t\t\t     *                  AU REVOIR.                *");
    printf("\n\n\t\t\t\t\t     *                                            *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\t\t");
}
//==================================================================================


int main(int argc, char *argv[])
{
    //-------------
    splashscreen();
    CarteTP();

    //----------
    FILE *f=NULL;
     system("cls");
        printf("\n \n");
        printf ( " %s", "\n\n\t\t1: Creation d''un arbre avec n doublets aleatoires (valeur, couleur) \n\n\n\t\t " ) ;
        for (int i = 0; i < 3; i++)
        {
            printf("* * *\t");
            Sleep(500);
        }
        printf ( " %s", "\n Le nombre des noeuds de votre arbre sans compter la racine  : \n " ) ;
         scanf ( " %d", &K ) ;
         Creer ( & Racine , & K ) ;
         if (K>0)
         {

        printf ( " %s", "\n\n\t\t------- Parcours Inordre de l''arbre: -------- \n\n\n" ) ;
        Inordre ( & Racine ) ;
        printf ( " %s", "\n\n\t\t ------- Dessin de l''arbre ------- \n\n\n\t\t" ) ;

        for (int i = 0; i < 5; i++)
        {
            printf("\t* * *");
            Sleep(500);
        }

        dessin(Racine);
        printf ( " %s", "\n\n\t\t ---> Arbre dessine avec succes ! \n\n\t\t" ) ;
        system("pause");
        system("cls");

    char continuer = 'o';

    while (continuer == 'o' || continuer == 'O')
    {   if (K>0)
         {


//==================================================================================

        printf ( " %s", "\n\n\t\t2: transformation du sous arbre gauche en une liste ordonnee decroissante \n " ) ;
        printf ( " %s", "\t\t\t et le sous arbre droit en une liste ordonnee croissante \n\n\n\t " ) ;
        for (int i = 0; i < 5; i++)
        {
            printf("\t* * *");
            Sleep(500);
        }
        Liste_g_decr ( & Racine ) ;
        Affich_l_g_decrois ( & Racine ) ;
        Liste_d_crois ( & Racine ) ;
        Affich_list_d_crois ( & Racine ) ;
        printf ( " %s", "\n\n\t\t ----- Dessin de l''arbre ----- \n\t\t\t" ) ;

        for (int i = 0; i < 5; i++)
        {
            printf("\t* * *");
            Sleep(500);
        }

        dessin(Racine);
        printf ( " %s", "\n\n\t\t ----> Arbre dessine avec succes ! \t" ) ;
        system("pause");
        system("cls");
        //==================================================================================

        printf ( " %s", "\n\t\t\t\t------- Menu -------- \n " ) ;
        printf ( " %s", "\n\t\t\t** Transformer le sous arbre gauche et le sous arbre droit (listes) obtenus tels que: \n\n" ) ;
        printf ( " %s", "\n\n\t\t\t\t 1: Les nombres des fils n1, n2,... sont generes par suite arithmetique \n " ) ;
        printf ( " %s", "\n\n\t\t\t\t 2: n1,n2,... sont generes aleatoirement(valeurs differentes) \n  " ) ;
        printf ( " %s", "\n\n\t\t\t\t 3: n1,n2,... sont generes aleatoirement(valeurs identiques) \n " ) ;
        printf ( " %s", "\n\t\t\t\t--------------- \n " ) ;
        printf ( " %s", " \n \n \t\t -> Entrer votre choix: \t" ) ;
        scanf ( " %d", &Choix ) ;
        if( ( Choix == 1 ))
        {

            printf ( " %s", "\n\n\t\t Entrer le pas de la suite k : \t" ) ;
            scanf ( " %d", &K ) ;
            if (K>=0)
            {


            Transf_g_suite ( & Racine, & K ) ;
            Transf_d_suite ( & Racine, & K ) ;
            Affich_arbre_trans ( & Racine ) ;
            printf ( " %s", "\n\n\t\t Dessin de l''arbre \t" ) ;

            for (int i = 0; i < 5; i++)
            {
                printf("\t* * *");
                Sleep(500);
            }

            dessin(Racine);
            printf ( " %s", "\n\n\t\t Arbre dessine avec succes ! \t" ) ;
            system("pause");
            system("cls");
            }
            else
            {
                                printf("\t \t \t Entrez un entier positif \n  ");
                    break;

            }
        } ;
        if( ( Choix == 2 ))
        {



            Transf_g_aleatoire ( & Racine ) ;
            Transf_d_aleatoire ( & Racine ) ;
            Affich_arbre_trans ( & Racine ) ;
            printf ( " %s", "\n\n\t\t Dessin de l''arbre \t" ) ;

            for (int i = 0; i < 5; i++)
            {
                printf("\t* * *");
                Sleep(500);
            }

            dessin(Racine);
            printf ( " %s", "\n\n\t\t Arbre dessine avec succes ! \t" ) ;
            system("pause");
            system("cls");
        }

    if( ( Choix == 3 ))
    {


        Transf_alea_ident ( & Racine ) ;
        printf ( " %s", "--------------- \n " ) ;
        Affich_arbre_trans ( & Racine ) ;
        printf ( " %s", "\n\n\t\t Dessin de l''arbre \t" ) ;

        for (int i = 0; i < 5; i++)
        {
            printf("\t* * *");
            Sleep(500);
        }

        dessin(Racine);
        printf ( " %s", "\n\n\t\t Arbre dessine avec succes ! \t" ) ;
        system("pause");
        system("cls");
    } ;

    if( ( ( Choix < 1 ) || ( Choix > 3 ) ))
    {
        printf ( " %s", "---------------" ) ;
        printf ( " %s", "\n\n\t\t Choix Incorrect! \n " ) ;
        printf ( " %s", "--------------- \n " ) ;
    } ;
    Choix  =  0 ;
    printf("\n\n\t\t Voulez continuez avec le meme arbre? (O/N)?");
    fflush(stdin);
    continuer = getchar();
} ;
}
         }
merci();
system("PAUSE");
return 0;
}
