# A-CRP

Include criada para ajudar na criacao de GM's e sistemas

# ClearChat(playerid, bool:Global = false, Quantia = 40)
*O que faz: Limpa Chat de todos ou de um player so*
*Parametros:*\
`playerid - Limpa o Chat do player escolhido`\
`bool:Global - Limpa o chat de todos caso colocado em TRUE`\
`Quantia - A quantidade de linhas limpas no chat`\
*Exemplo:*
```
public OnPlayerConnect(playerid)
{
  ClearChat(playerid);
  return 1;
}
```

# FormatarGrana(Valor, bool:Sifao = false)

* O que faz: Deixa o valor colocar com pontuacao (1000 ira virar 1.000)*
*Parametros:*\
`Valor - Quantidade para ser pontuada`\
`bool:Sifao - Coloca o sifao na pontuacao caso esteja em TRUE`\
*Exemplo:*
```
FormatarGrana(100000, true);
// Resultado vira uma string assim: "$100.000"
```
