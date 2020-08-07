# Projeto_testerepresentacional
Projeto apresentado no 1o Semestre da Graduação de TADS

FALHAS ENCONTRADAS NO PROJETO CONCLUÍDO:
- Não consegui salvar no formato tabelado.
- O questionário não está sendo salvo com as devidas acentuações...
- A leitura de arquivo, consequentemente, não está sendo feita corretamente devido acentuações.


Objetivo
Gerar a aplicação (em Linguagem C) para identificar o perfil representacional de um

indivíduo

OBSERVAÇÕES IMPORTANTES:
-o projeto DEVE ser realizado INDIVIDUALMENTE ou EM DUPLA;
-a realização da avaliação consiste na APRESENTAÇÃO do projeto em laboratório
de informática durante a qual os alunos serão arguidos sobre como realizaram o
projeto;
-SERÃO DESCONSIDERADOS projetos cujos autores não realizem a APRESENTAÇÃO em
laboratório de informática.
O que são sistemas representacionais
Usamos os sentidos externos para observar o mundo e os internos para representar a experiência para nós mesmos.
As maneiras como assimilamos, armazenamos e codificamos a informação na nossa mente através da visão, da
audição, do tato, do paladar ou do olfato são chamadas de sistemas representacionais.
Identificar os sistemas representacionais das pessoas nos ajuda a nos comunicarmos melhor.
Referencial teórico
Segundo Albert Merabian, em seu livro “Silent Messages”, o poder de influência das palavras não passa de 7%,
enquanto a forma como as palavras são ditas e a fisiologia representam 38% e 55% deste poder, respectivamente.
Para Merabian 55% do impacto da comunicação é não-verbal. Corresponde à postura, gestos e contato visual da
pessoa enquanto se comunica.
O tom da voz representa 38% do impacto da comunicação.
Por fim, as palavras propriamente ditas detêm 7% do impacto da comunicação.
Assim sendo, conclui Merabian, não é o que dizemos, mas como dizemos que faz a diferença na comunicação.
As portas da percepção são os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos únicos pontos de
contato com o mundo exterior. Da mesma forma que utilizamos os sentidos para filtrarmos as experiências,
utilizamos os sentidos para estruturar nosso pensamento e nossa comunicação.
De acordo com a Programação Neurolinguística existem os seguintes sistemas representacionais.
- Auditivo
- Digital
- Cinestésico
- Visual
Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas
auditivas.
Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as
digitais.
As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as
sensações internas e as emoções.
Já as pessoas visuais aprendem melhor quando se valendo da visão.
Cada pessoa tem um sistema representacional predominante e adequar a comunicação ao sistema representacional
dominante dela é fundamental para diálogos eficientes.

INSTITUTO FEDERAL DE SÃO PAULO - IFSP
Disciplina LG1A1 Ano/Semestre Letivo 2019/02
Professoras Eurides Balbino
André Evandro

Data de apresentação 27/11/2019

PROJETO DA DISCIPLINA

2

Teste do sistema representacional
Nas frases a seguir, pontue com:
4 a que melhor descreve você;
3 a próxima melhor descrição;
2 a próxima melhor; e
1 aquela que menos descreve você.
1. Eu tomo decisões importantes baseado em
____ intuição
____ o que me soa melhor
____ o que me parece melhor
____ um estudo preciso e minucioso do assunto
2. Durante uma discussão eu sou mais influenciado por
____ o tom da voz da outra pessoa
____ se eu posso ou não ver o argumento da outra pessoa
____ a lógica do argumento da outra pessoa
____ se eu entro em contato ou não com os sentimentos reais do outro.
3. Eu comunico mais facilmente o que se passa comigo
____ do modo como me visto e aparento
____ pelos sentimentos que compartilho
____ pelas palavras que escolho
____ pelo tom da minha voz
4. É muito fácil para mim
____ achar o volume e a sintonia ideais num sistema de som
____ selecionar o ponto mais relevante relativo a um assunto interessante
____ escolher os móveis mais confortáveis
____ escolher as combinações de cores mais ricas e atraentes
5. Eu me percebo assim
____ se estou muito em sintonia com os sons dos ambientes
____ se sou muito capaz de raciocinar com fatos e dados novos
____ eu sou muito sensível à maneira como a roupa veste o meu corpo
____ eu respondo fortemente às cores e à aparência de uma sala
Marque abaixo a seqüência das pontuações para cada questão.
1 2 3 4 5
____ C ____ A ____ V ____ A ____ A
____ A ____ V ____ C ____ D ____ D
____ V ____ D ____ D ____ C ____ C
____ D ____ C ____ A ____ V ____ V
Transponha essas respostas para a grade abaixo e some os números associados com cada letra.
Questão V C A D
1
2
3
4
5
TOTAL X 2

% VISUAL % CINESTÉSICO % AUDITIVO % DIGITAL

3

O projeto da disciplina
Feitas estas considerações, você deverá elaborar o programa em Linguagem C que implemente o teste
apresentado.
Para tanto, o projeto deverá possuir as seguintes características.
1. Ao iniciar a execução, exibir uma tela de login para que o usuário informe seu nome e prontuário,
conforme exemplificado abaixo.

1.1 Os dados fornecidos no login serão usados para identificar o arquivo que conterá o resultado do
teste. No exemplo acima, o arquivo gerado pelo teste deverá se chamar
“RESULTADO_EURIDES_BALBINO_S07102X.TXT”.
1.2 Assim, para cada espaço em branco no nome do usuário o programa deverá substituir por um
underline (_) e depois associar com o número do prontuário, pois essas informações do usuário serão
usadas para identificar o arquivo gerado (RESULTADO_NOME_PRONTUÁRIO.TXT).
2. Caso o nome do usuário seja “MASTER”, o programa deverá apresentar a tela com menu de opções
conforme a seguir. O menu deverá executar em looping até que seja escolhida a opção “F. Fim”. O
programa deve aceitar “F” ou “f”.

2.1 A opção “1. Cadastrar questionário” deverá gerar o arquivo
“TESTE_SISTEMA_REPRESENTACIONAL.DAT”, cujo layout dos registros deverá ser o seguinte:
NroFrase Frase cinestesico item_1 auditivo item_2 visual item_3 digital item_4
int char frase[100] int char item_1[100] int char item_2[100] int char item_3[100] int char item_4[100]
2.2 Para tanto, o programa deverá usar uma tabela de 5 elementos do tipo do layout acima; abastecer a
tabela com os dados abaixo e gravá-la no arquivo “TESTE_SISTEMA_REPRESENTACIONAL.DAT”.
Concluída a gravação, o programa deve retornar ao menu de opções.

3. A opção “2. Visualizar questionário” deverá ler o conteúdo do arquivo
“TESTE_SISTEMA_REPRESENTACIONAL.DAT”; gerar o arquivo “QUESTIONÁRIO_1.TXT” conforme
modelo abaixo e exibir o questionário em tela usando o aplicativo bloco de notas (Notepad.exe).
Concluída a exibição, o programa deve retornar ao menu de opções.

4
4. A opção “3. Realizar teste” deverá funcionar conforme os itens a seguir. Adicionalmente, quando o
usuário logado não for “MASTER”, o processo de avaliação deve ser iniciado imediatamente após o login.
4.1 Apresentar as instruções abaixo junto com cada frase.

4.2 Os únicos valores aceitos devem ser 4,3,2,1.
4.3 Não pode haver itens pontuados com o mesmo valor (por exemplo, não pode atribuir o valor 4 para
[a] e para [b]).
4.4 Após a pontuação dos itens da última frase, computar os somatórios para cada sistema
representacional: C (cinestésico), A (auditivo), V (visual) e D (digital). A porcentagem de cada sistema
representacional é o resultado do dobro do respectivo somatório (vide exemplo abaixo).

4.5 Descubra qual o maior valor para identificar o perfil do avaliado.
4.6 Monte o arquivo contendo o resultado da avaliação conforme abaixo, lembrando que o nome do
arquivo deve ser RESULTADO_NOME_PRONTUÁRIO.TXT (onde NOME e PRONTUÁRIO são os informados no
login). Esse arquivo deverá ser exibido em tela usando o aplicativo bloco de notas (Notepad.exe).
Concluída a exibição, o programa deve retornar ao menu de opções.

5. A opção “4. Sobre o teste” deverá exibir em tela o conteúdo do arquivo REFERENCIAL_TEORICO.TXT,
conforme ilustrado abaixo, usando o aplicativo bloco de notas (Notepad.exe). Concluída a exibição, o
programa deve retornar ao menu de opções.

6. A opção “F. Fim” deve finalizar a execução do programa. O programa deve aceitar “F” ou “f”.
7. Caso seja escolhida alguma opção não constante no menu, o programa deve exibir a tela com a
mensagem de erro a seguir. Concluída a exibição, o programa deve retornar ao menu de opções.
