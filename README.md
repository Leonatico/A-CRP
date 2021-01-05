# A-CRP

Include criada para ajudar na criacao de GM's e sistemas

# ClearChat(playerid, bool:Global = false, Quantia = 40)
*O que faz: Limpa Chat de todos ou de um player so*
*Parametros:*\
`playerid - Limpa o Chat do player escolhido`\
`Global - Limpa o chat de todos caso colocado em TRUE`\
`Quantia - A quantidade de linhas limpas no chat`\
*Exemplo:*
```
public OnPlayerConnect(playerid)
{
  ClearChat(playerid);
  return 1;
}```

# FormatarGrana(Valor, bool:Sifao = false);
