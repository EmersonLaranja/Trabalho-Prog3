#!/bin/bash

mainclass="Main"

ant compile
capitais=("belo-horizonte" "cariacica" "rio-de-janeiro" "sao-paulo" "serra" "vila-velha" "vitoria")

mkdir out
mkdir diff

cd bin
for i in ${capitais[@]} ; do
    echo "$i-cadidatos.csv $i-partidos.csv"
    java ${mainclass} ../testes/${i}/in/candidatos.csv ../testes/${i}/in/partidos.csv 15/11/2020 > ../out/saida-${i}.txt
done


cd ..
for i in ${capitais[@]} ; do
    diff out/saida-${i}.txt ./testes/${i}/out/output.txt > diff/saida-${i}.txt
done