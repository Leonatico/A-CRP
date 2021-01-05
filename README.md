# A-CRP

Include criada para ajudar na criacao de GM's e sistemas

# ClearChat(playerid, bool:Global = false, Quantia = 40)
O que faz: Limpa Chat de todos ou de um player so
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
O que faz: Deixa o valor colocar com pontuacao (1000 ira virar 1.000)
*Parametros:*\
`Valor - Quantidade para ser pontuada`\
`bool:Sifao - Coloca o sifao na pontuacao caso esteja em TRUE`\
*Exemplo:*
```
FormatarGrana(100000, true);
// Resultado vira uma string assim: "$100.000"
```

# GetVehicleName(vehicleid)
O que faz: Pega o nome do veiculo
*Parametros:*\
`vehicleid - ID do veiculo (400 a 611)`\
*Exemplo:*
```
new String[128];
format(String, 128, "Nome do veiculo: %s", GetVehicleName(451));
// Resultado vira assim: "Nome do veiculo: Turismo"
```

# MensagemP(const Mensagem[], Float:X, Float:Y, Float:Z, Cor, Float:Raio)
O que faz: Manda mensagem em area numa coordenada
*Parametros:*\
`Mensagem - String com a mensagem`\
`X, Y, Z - Coordenadas da mensagem em area`\
`Cor - Cor da mensagem`\
`Raio - Raio da mensagem`\
*Exemplo:*
```
MensagemP("Ola pessoas", 0.0000, 0.0000, 0.0000, 0xFFFFFFAA, 5.0);
```

# GetPlayerSpeedKM(playerid)
O que faz: Pega a velocidade em KM 
*Parametros:*\
`playerid - ID do player que vai medir a velocidade`\
*Exemplo:*
```
new Velocidade = floatround(GetPlayerSpeedKM(playerid));
```

# GetPlayerSpeedMPH(playerid)
O que faz: Pega a velocidade em MPH
*Parametros:*\
`playerid - ID do player que vai medir a velocidade`\
*Exemplo:*
```
new Velocidade = floatround(GetPlayerSpeedMPH(playerid));
```
