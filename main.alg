
   SOIENT
       Racine : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       SOIT K , I , Choix : ENTIER ;
       SOIT Choix2 : BOOLEEN ;
       Creer , Liste_g_decr , Liste_d_crois : ACTION ;
       Transf_g_suite , Transf_d_suite , Transf_g_aleatoire , Transf_d_aleatoire , Transf_alea_ident : ACTION ;
       Rotation_gauche , Rotation_droite DES FONCTION ( ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ) ;
       Nbnoeuds : FONCTION ( ENTIER ) ;
       Inordre , Affich_list_d_crois , Affich_l_g_decrois , Affich_arbre_trans : ACTION ;
      
   DEBUT
       TQ ( 1 = 1 ) :
           ECRIRE ( '------- Menu --------' ) ;
           ECRIRE ( '1: Creer un arbre avec n doublets aléatoires' ) ;
           ECRIRE ( '2: transformer le sous arbre gauche en une liste ordonnée décroissante' ) ;
           ECRIRE ( ' et le sous arbre droit en une liste ordonnée croissante' ) ;
           ECRIRE ( '** Transformer le sous arbre gauche et le sous arbre droit (listes) obtenus tels que: ' ) ;
           ECRIRE ( '3: n1, n2,... sont générés par suite arithmétique' ) ;
           ECRIRE ( '4: n1,n2,... sont générés aléatoirement(valeurs différentes ' ) ;
           ECRIRE ( '5: n1,n2,... sont générés aléatoirement(valeurs identiques)' ) ;
           ECRIRE ( '---------------' ) ;
           ECRIRE ( '' ) ;
           LIRE ( Choix ) ;
           SI ( Choix = 1 ) :
               ECRIRE ( 'Le nombre des noeuds de votre arbre sans compter la racine  ' ) ;
               LIRE ( K ) ;
               SI ( K > 0 ) :
                   APPEL Creer ( Racine , K ) ;
                   ECRIRE ( '---------------' ) ;
                   ECRIRE ( '------- Parcours Inordre de l''arbre: --------' ) ;
                   ECRIRE ( 'VRAI = Couleur Blanc' ) ;
                   ECRIRE ( 'FAUX = Couleur Noir' ) ;
                   APPEL Inordre ( Racine ) ;
                   Choix2 := FAUX ;
                  
               FSI ;
              
           FSI ;
           SI ( Choix = 2 ) :
               SI ( Racine <> NIL ) :
                   APPEL Liste_g_decr ( Racine ) ;
                   APPEL Affich_l_g_decrois ( Racine ) ;
                   APPEL Liste_d_crois ( Racine ) ;
                   APPEL Affich_list_d_crois ( Racine ) ;
                   Choix2 := VRAI ;
                  
               SINON
                   ECRIRE ( 'Creer l''arbre d''abord ' ) ;
                  
               FSI ;
              
           FSI ;
           SI ( Choix = 3 ) :
               SI ( Racine <> NIL ) :
                   SI ( Choix2 = VRAI ) :
                       ECRIRE ( 'Entrer le pas de la suite k : ' ) ;
                       LIRE ( K ) ;
                       SI ( K > 0 ) :
                           APPEL Transf_g_suite ( Racine , K ) ;
                           APPEL Transf_d_suite ( Racine , K ) ;
                           APPEL Affich_arbre_trans ( Racine ) ;
                           ECRIRE ( '---------------' ) ;
                           Choix2 := FAUX ;
                          
                       SINON
                           ECRIRE ( 'Entrez un entier positif ' ) ;
                          
                       FSI ;
                      
                   SINON
                       ECRIRE ( 'Transformez l''arbre en une liste croissant et autre décroissante ' ) ;
                      
                   FSI ;
                  
               SINON
                   ECRIRE ( 'Creer l''arbre d''abord ' ) ;
                  
               FSI ;
              
           FSI ;
           SI ( Choix = 4 ) :
               SI ( Racine <> NIL ) :
                   SI ( Choix2 = VRAI ) :
                       APPEL Transf_g_aleatoire ( Racine ) ;
                       APPEL Transf_d_aleatoire ( Racine ) ;
                       APPEL Affich_arbre_trans ( Racine ) ;
                       Choix2 := FAUX ;
                      
                   SINON
                       ECRIRE ( 'Transformez l''arbre en une liste croissante et autre décroissante ' ) ;
                      
                   FSI ;
                  
               SINON
                   ECRIRE ( 'Creer l''arbre d''abord ' ) ;
                  
               FSI ;
              
           FSI ;
           SI ( Choix = 5 ) :
               SI ( Racine <> NIL ) :
                   SI ( Choix2 = VRAI ) :
                       APPEL Transf_alea_ident ( Racine ) ;
                       ECRIRE ( '---------------' ) ;
                       APPEL Affich_arbre_trans ( Racine ) ;
                       Choix2 := FAUX ;
                      
                   SINON
                       ECRIRE ( 'Transformez l''arbre en une liste croissante et autre décroissante ' ) ;
                      
                   FSI ;
                  
               SINON
                   ECRIRE ( 'Creer l''arbre d''abord ' ) ;
                  
               FSI ;
              
           FSI ;
           SI ( ( Choix < 1 ) OU ( Choix > 5 ) ) :
               ECRIRE ( '---------------' ) ;
               ECRIRE ( 'Choix Incorrect!' ) ;
               ECRIRE ( '---------------' ) ;
              
           FSI ;
           Choix := 0 ;
          
       FTQ ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------**/
   ACTION Creer ( Racine , K )
   SOIENT
       Racine , Racined , Racineg , P , Q , New : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       Noeud UNE STRUCTURES ( ENTIER , BOOLEEN ) ;
       N , Ng , Nd , K : ENTIER ;
      
   DEBUT
       Racined:=NIL;
       Racineg:=NIL;
       Racine:=NIL;
       N := K ;
       Nd := N / 2 ;
       Ng := N - Nd ;
       AFF_STRUCT ( Noeud , 1 , 1000 ) ;
       AFF_STRUCT ( Noeud , 2 , FAUX ) ;
       CREERNOEUD ( Racine ) ;
       AFF_INFO ( Racine , Noeud ) ;
       POUR I := 1 , Ng :
           AFF_STRUCT ( Noeud , 1 , ALEANOMBRE ( 1000 ) ) ;
           AFF_STRUCT ( Noeud , 2 , FAUX ) ;
           CREERNOEUD ( New ) ;
           AFF_INFO ( New , Noeud ) ;
           SI Racineg = NIL
               Racineg := New ;
              
           SINON
               P := Racineg ;
               Q := P ;
               TQ ( ( P <> NIL ) ET ( Q <> NIL ) ) :
                   Q := P ;
                   SI STRUCT ( INFO ( New ) , 1 ) < STRUCT ( INFO ( P ) , 1 ) :
                       P := FG ( P )
                   SINON
                       SI STRUCT ( INFO ( New ) , 1 ) > STRUCT ( INFO ( P ) , 1 )
                           P := FD ( P ) ;
                          
                       SINON
                           Q := NIL ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FTQ ;
               SI ( Q <> NIL ) :
                   SI ( STRUCT ( INFO ( New ) , 1 ) < STRUCT ( INFO ( Q ) , 1 ) ) :
                       AFF_FG ( Q , New ) ;
                      
                   FSI ;
                   SI ( STRUCT ( INFO ( New ) , 1 ) > STRUCT ( INFO ( Q ) , 1 ) ) :
                       AFF_FD ( Q , New ) ;
                      
                   FSI ;
                  
               SINON
                   LIBERERNOEUD ( New ) ;
                   Ng := Ng + 1 ;
                   Q := P ;
                  
               FSI ;
              
           FSI ;
          
       FPOUR ;
       POUR I := 1 , Nd :
           AFF_STRUCT ( Noeud , 1 , ALEANOMBRE ( 1000 ) ) ;
           AFF_STRUCT ( Noeud , 2 , VRAI ) ;
           CREERNOEUD ( New ) ;
           AFF_INFO ( New , Noeud ) ;
           SI Racined = NIL
               Racined := New ;
              
           SINON
               P := Racined ;
               Q := P ;
               TQ ( ( P <> NIL ) ET ( Q <> NIL ) ) :
                   Q := P ;
                   SI STRUCT ( INFO ( New ) , 1 ) < STRUCT ( INFO ( P ) , 1 ) :
                       P := FG ( P )
                   SINON
                       SI STRUCT ( INFO ( New ) , 1 ) > STRUCT ( INFO ( P ) , 1 )
                           P := FD ( P ) ;
                          
                       SINON
                           Q := NIL ;
                          
                       FSI ;
                      
                   FSI ;
                  
               FTQ ;
               SI ( Q <> NIL ) :
                   SI ( STRUCT ( INFO ( New ) , 1 ) < STRUCT ( INFO ( Q ) , 1 ) ) :
                       AFF_FG ( Q , New ) ;
                      
                   FSI ;
                   SI ( STRUCT ( INFO ( New ) , 1 ) > STRUCT ( INFO ( Q ) , 1 ) ) :
                       AFF_FD ( Q , New ) ;
                      
                   FSI ;
                  
               SINON
                   LIBERERNOEUD ( New ) ;
                   Nd := Nd + 1 ;
                   Q := P ;
                  
               FSI ;
              
           FSI ;
          
       FPOUR ;
       AFF_FG ( Racine , Racineg ) ;
       AFF_FD ( Racine , Racined ) ;
       ECRIRE ( '------- Arbre Créé!  --------' ) ;
      
   FIN
  /**-----------------------------------------------------------------------------------------------------------**/
   ACTION Inordre ( Racine ) ;
   SOIENT
       Racine : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       P : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       P := Racine ;
       SI ( P <> NIL ) :
           APPEL Inordre ( FG ( P ) ) ;
           ECRIRE ( INFO ( P ) ) ;
           ECRIRE ( '' ) ;
           APPEL Inordre ( FD ( P ) ) ;
          
       FSI ;
      
   FIN
  /**-----------------------------------------------------------------------------------------------------------**/
   FONCTION Rotation_gauche ( R ) : ARB DE STRUCTURES ( ENTIER , BOOLEEN )
   SOIENT
       R , P , Tmp UN ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       P := R ;
       Tmp := FD ( P ) ;
       SI ( Tmp <> NIL ) :
           AFF_FD ( P , FG ( Tmp ) ) ;
           AFF_FG ( Tmp , P ) ;
          
       FSI ;
       Rotation_gauche := Tmp ;
      
   FIN
  /**-----------------------------------------------------------------------------------------------------------**/
   FONCTION Rotation_droite ( R ) : ARB DE STRUCTURES ( ENTIER , BOOLEEN )
   SOIENT
       R , Tmp UN ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       Tmp := FG ( R ) ;
       SI ( Tmp <> NIL ) :
           AFF_FG ( R , FD ( Tmp ) ) ;
           AFF_FD ( Tmp , R ) ;
          
       FSI ;
       Rotation_droite := Tmp ;
      
   FIN
  /**------------------------------------------------------------------------------------------------------------**/
   ACTION Liste_d_crois ( R )
   SOIENT
       R , P , Sauv : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       Sauv := R ;
       P := R ;
       R := FD ( R ) ;
       TQ ( R <> NIL ) :
           TQ ( FG ( R ) <> NIL ) :
               R := Rotation_droite ( R ) ;
               AFF_FD ( P , R ) ;
              
           FTQ ;
           P := R ;
           R := FD ( R ) ;
          
       FTQ ;
       R := Sauv ;
      
   FIN
  /**--------------------------------------------------------------------------------------------------------------**/
   ACTION Affich_list_d_crois ( R )
   SOIENT
       R , P : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( '------- Liste droite croissante  --------' ) ;
       P := FD ( R ) ;
       TQ ( P <> NIL ) :
           ECRIRE ( INFO ( P ) ) ;
           P := FD ( P ) ;
          
       FTQ ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Liste_g_decr ( R )
   SOIENT
       R , P , Sauv UN ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       Sauv := R ;
       P := R ;
       R := FG ( R ) ;
       TQ ( R <> NIL ) :
           TQ ( FD ( R ) <> NIL ) :
               R := Rotation_gauche ( R ) ;
               AFF_FG ( P , R ) ;
              
           FTQ ;
           P := R ;
           R := FG ( R ) ;
          
       FTQ ;
       R := Sauv ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Affich_l_g_decrois ( R )
   SOIENT
       R , P : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( '------- Liste gauche décroissante  --------' ) ;
       P := FG ( R ) ;
       TQ ( P <> NIL ) :
           ECRIRE ( INFO ( P ) ) ;
           P := FG ( P ) ;
          
       FTQ ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   FONCTION Nbnoeuds ( R ) : ENTIER ;
   SOIT
       R : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI ( R = NIL )
           Nbnoeuds := 0 ;
          
       SINON
           Nbnoeuds := ( 1 + Nbnoeuds ( FG ( R ) ) + Nbnoeuds ( FD ( R ) ) ) ;
          
       FSI
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Transf_g_suite ( R , K )
   SOIENT
       P , R , Sauv : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       K , N : ENTIER ;
      
   DEBUT
       Sauv := R ;
       P := R ;
       R := FG ( R ) ;
       N := K ;
       TQ ( R <> NIL ) :
           SI ( Nbnoeuds ( FD ( R ) ) < N ) :
               R := Rotation_droite ( R ) ;
               SI ( R <> NIL )
                   AFF_FG ( P , R ) ;
                  
               FSI
           SINON
               P := R ;
               R := FG ( R ) ;
               N := N + K ;
              
           FSI
       FTQ ;
       R := Sauv ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Transf_d_suite ( R , K )
   SOIENT
       P , R , Sauv : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       K , N : ENTIER ;
      
   DEBUT
       Sauv := R ;
       P := R ;
       R := FD ( R ) ;
       N := K ;
       TQ ( R <> NIL ) :
           SI ( Nbnoeuds ( FG ( R ) ) < N ) :
               R := Rotation_gauche ( R ) ;
               SI ( R <> NIL )
                   AFF_FD ( P , R ) ;
                  
               FSI
           SINON
               P := R ;
               R := FD ( R ) ;
               N := N + K ;
              
           FSI ;
          
       FTQ ;
       R := Sauv ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Transf_d_aleatoire ( R )
   SOIENT
       P , R , Sauv : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       K , N : ENTIER ;
      
   DEBUT
       Sauv := R ;
       P := R ;
       R := FD ( R ) ;
       N := ALEANOMBRE ( 2 ) + 3 ;
       TQ ( R <> NIL ) :
           SI ( Nbnoeuds ( FG ( R ) ) < N ) :
               R := Rotation_gauche ( R ) ;
               SI ( R <> NIL )
                   AFF_FD ( P , R ) ;
                  
               FSI
           SINON
               P := R ;
               R := FD ( R ) ;
               N := ALEANOMBRE ( 2 ) + 3 ;
              
           FSI ;
          
       FTQ ;
       R := Sauv ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Transf_g_aleatoire ( R )
   SOIENT
       P , R , Sauv : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       K , N : ENTIER ;
      
   DEBUT
       Sauv := R ;
       P := R ;
       R := FG ( R ) ;
       N := ALEANOMBRE ( 2 ) + 1 ;
       TQ ( R <> NIL )
           SI ( Nbnoeuds ( FD ( R ) ) < N ) :
               R := Rotation_droite ( R ) ;
               SI ( R <> NIL )
                   AFF_FG ( P , R ) ;
                  
               FSI
           SINON
               P := R ;
               R := FG ( R ) ;
               N := ALEANOMBRE ( 2 ) + 1 ;
              
           FSI ;
          
       FTQ ;
       R := Sauv ;
      
   FIN
  /**-------------------------------------------------------------------------------------------------------------**/
   ACTION Transf_alea_ident ( R )
   SOIENT
       N : ENTIER ;
       R , P_gauche , P_droit , R_gauche , R_droit , Sauv : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       Stop1 , Stop2 : BOOLEEN ;
      
   DEBUT
       Sauv := R ;
       Stop1 := FAUX ;
       Stop2 := FAUX ;
       P_gauche := R ;
       P_droit := R ;
       R_gauche := FG ( R ) ;
       R_droit := FD ( R ) ;
       N := ALEANOMBRE ( 4 ) + 1 ;
       TQ ( ( R_gauche <> NIL ) OU ( R_droit <> NIL ) ) :
           TQ ( ( R_gauche <> NIL ) ET NON ( Stop1 ) )
               SI ( Nbnoeuds ( FD ( R_gauche ) ) < N ) :
                   R_gauche := Rotation_droite ( R_gauche ) ;
                   SI ( R_gauche <> NIL )
                       AFF_FG ( P_gauche , R_gauche ) ;
                      
                   FSI
               SINON
                   P_gauche := R_gauche ;
                   R_gauche := FG ( R_gauche ) ;
                   Stop1 := VRAI ;
                  
               FSI ;
              
           FTQ ;
           TQ ( ( R_droit <> NIL ) ET NON ( Stop2 ) )
               SI ( Nbnoeuds ( FG ( R_droit ) ) < N ) :
                   R_droit := Rotation_gauche ( R_droit ) ;
                   SI ( R_droit <> NIL )
                       AFF_FD ( P_droit , R_droit ) ;
                      
                   FSI
               SINON
                   P_droit := R_droit ;
                   R_droit := FD ( R_droit ) ;
                   Stop2 := VRAI ;
                  
               FSI ;
              
           FTQ ;
           N := ALEANOMBRE ( 4 ) + 1 ;
           Stop1 := FAUX ;
           Stop2 := FAUX ;
          
       FTQ ;
       R := Sauv ;
      
   FIN
  /**--------------------------------------------------------------------------------------------------**/
   ACTION Affich_arbre_trans ( R )
   SOIENT
       R , Pg , Pd , F : ARB DE STRUCTURES ( ENTIER , BOOLEEN ) ;
       N : ENTIER ;
      
   DEBUT
       N := 1 ;
       ECRIRE ( '------- Affichage de l''arbre aprés transformation: --------' ) ;
       ECRIRE ( 'VRAI = Couleur Blanc' ) ;
       ECRIRE ( 'FAUX = Couleur Noir' ) ;
       ECRIRE ( '---------------------' ) ;
       ECRIRE ( 'Racine: ' ) ;
       ECRIRE ( INFO ( R ) ) ;
       ECRIRE ( '---------------------' ) ;
       Pg := FG ( R ) ;
       Pd := FD ( R ) ;
       TQ ( Pg <> NIL ) OU ( Pd <> NIL ) :

           ECRIRE ( 'Gauche: ' ) ;
           F := Pg ;
           TQ ( F <> NIL ) :
               ECRIRE ( INFO ( F ) ) ;
               F := FD ( F ) ;
              
           FTQ ;
           ECRIRE ( '----' ) ;
           ECRIRE ( 'Droit: ' ) ;
           F := Pd ;
           TQ ( F <> NIL ) :
               ECRIRE ( INFO ( F ) ) ;
               F := FG ( F ) ;
              
           FTQ ;
           ECRIRE ( '---------------------' ) ;
           N := N + 1 ;
           SI ( Pg <> NIL ) :
               Pg := FG ( Pg ) ;
              
           FSI ;
           SI ( Pd <> NIL ) :
               Pd := FD ( Pd ) ;
              
           FSI ;
          
       FTQ ;
      
   FIN
