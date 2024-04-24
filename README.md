# ATIVIDADE DA 1ª UNIDADE DE LINGUAGEM DE PROGRAMAÇÃO I (IMD0030)

Esse é o projeto da primeira unidade da disciplina de LP1 em que se aplica os conceitos de programação orientada o objetos utilizando a linguagem de programação C++.

# OBJETIVO

O objetivo é desenvolver um sistema de gestão de astronautas e voos espaciais que deve contém as seguintes funcionalidades:

* Cadastro de astronautas com cpf, nome, idade
* Cadastro de voos com um código e lista de passageiros
* Adicionar astronautas em voos (por cpf e somente se o voo está em planejamento)
* Remover Astronauta de um Voo (por cpf e somente se o voo está em planejamento)
* Lançar um voo
    * Precisa que tenha pelo menos 1 astronauta e todos estarem disponíveis
    * Astronautas dele ficam indisponíveis
* Explodir voo (astronautas morrem e não podem ser adicionados em outros voos)
* Finalizar um voo (com sucesso)
    * Astronautas dele voltam a ficar disponíveis
* Listar todos os voos (com os seus astronautas)
    * Planejados (com os astronautas)
    * Em curso (com os astronautas)
    * Finalizados (com os astronautas que estavam nele)
        * sinalizar se finalizado com sucesso ou não
* Listar todos os astronautas mortos
    * cpf, nome, voos que participou

# COMO COMPILAR

Para compilar o projeto basta executar o comando:
```
make
```

# COMO EXECUTAR

Execute o projeto da seguinte forma:
```
./bin/lp1
```