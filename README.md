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

# PlayerName(playerid)
O que faz: Pega o Nick do player
*Parametros:*\
`playerid - ID do player que vai ser pego o nick`\
*Exemplo:*
```
format(String, 128, "Nome do player: %s", PlayerName(playerid));
// Resultado fica assim: "Nome do player: Leonatico"
```

# KickMessage(playerid, Cor, const text[])
O que faz: Da kick no player e manda mensagem antes do kick
*Parametros:*\
`playerid - ID do player que vai ser kickado e enviado a mensagem`\
`Cor - Cor da mensagem`\
`text - Conteudo da mensagem`\
*Exemplo:*
```
KickMessage(playerid, 0xFFFFFFAA, "Voce acaba de ser Kickado");
```

# BanMessage(playerid, Cor, const text[])
O que faz: Da ban no player e manda mensagem antes do ban
*Parametros:*\
`playerid - ID do player que vai ser banido e enviado a mensagem`\
`Cor - Cor da mensagem`\
`text - Conteudo da mensagem`\
*Exemplo:*
```
KickMessage(playerid, 0xFFFFFFAA, "Voce acaba de ser BANIDO");
```

# WeaponName(weaponid)
O que faz: Pega o nome da arma pelo ID
*Parametros:*\
`weaponid - ID da arma`\
*Exemplo:*
```
format(String, 128, "Nome arma: %s", WeaponName(24));
// Resultado fica assim: "Nome arma: Desert Eagle"
```

# FreezeTemp(playerid, Temp)
O que faz: Congela o player por um tempo determinado
*Parametros:*\
`playerid - ID do player que ira ser congelado`\
`Temp - Tempo que ira ficar congelado em milisegundos`\
*Exemplo:*
```
FreezeTemp(playerid, 2000);
```

# SCMProx(playerid, color, const text[], Float:distance)
O que faz: Manda mensagem em area pelas coordenadas de um player
*Parametros:*\
`playerid - ID do player que ira ser pego as cords`\
`Color - Cor da mensagem que ira ser mandada`\
`text - Conteudo da mensagem`\
`distance - Distancia que ira mandar a mensagem`\
*Exemplo:*
```
SCMProx(playerid, 0xFFFFFFAA, "Ola pessoas", 10.0);
```

# VerificarProximo(playerid, targetid, Float:Raio)
O que faz: Verifica se um player esta perto do outro escolhido
*Parametros:*\
`playerid - ID do player numero 1 que ira ser verificado`\
`targetid - ID do player numero 2 que ira ser verificado`\
`Raio - Distancia dos players`\
*Exemplo:*
```
if(VerificarProximo(playerid, targetid, 10.0))
```

# PlayerIp(playerid) {Esta em teste, Algumas vezes foi puxado o IP e relatou como 255.255.255.255, iremos resolver}
O que faz: Puxa o IP de um player 
*Parametros:*\
`playerid - ID do player que ira ser puxado o IP`\
*Exemplo:*
```
format(String, 128, "IP: %s", PlayerIp(playerid));
// Resultado fica assim: "IP: 127.0.0.1" (IP local como desmontracao)
```
