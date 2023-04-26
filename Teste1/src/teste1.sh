#!/bin/bash

##################################################################################################################################
# Teste Happy Number
##################################################################################################################################

echo "######################################"
echo "##Inicio Teste Unitario Happy Number##"
echo "######################################"

echo "Digite o numero a validar: "
read valor

e_numero='^-?[0-9]+([.][0-9]+)?$'
if ! [[ $valor =~ $e_numero ]] ; then
   echo "Erro o valor digitado nao e um numero inteiro"
   exit 1
fi

./happynumber $valor

echo "######################################"
echo "###Fim Teste Unitario Happy Number###"
echo "######################################"