# A-CRP

Include criada para ajudar na criacao de GM's e sistemas

# ClearChat
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
