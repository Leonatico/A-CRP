/*
    Include CRP
    Criado por: Leonatico
    facilita a criação de versões de GM's
*/

/*
FUNCTIONS:
native ClearChat(playerid, bool:Global = false, Quantia = 40);
native FormatarGrana(Valor, bool:Sifao = false);
native GetVehicleName(vehicleid);
native MensagemP(const Mensagem[], Float:X, Float:Y, Float:Z, Cor, Float:Raio);
native GetPlayerSpeedKM(playerid);
native GetPlayerSpeedMPH(playerid);
native PlayerName(playerid);
native KickMessage(playerid, Cor, const text[]);
native BanMessage(playerid, Cor, const text[]);
native WeaponName(weaponid);
native FreezeTemp(playerid, Temp);
native SCMProx(playerid, color, const text[], Float:distance);
native VerificarProximo(playerid, targetid, Float:Raio);
native PlayerIp(playerid);

*/

#include a_samp

stock VerificarProximo(playerid, targetid, Float:Raio)
{
    new Float:Pos[3];
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    if(IsPlayerInRangeOfPoint(targetid, Raio, Pos[0], Pos[1], Pos[2]))
    {
        return 1;
    }
    return 0;
}

stock SCMProx(playerid, color, const text[], Float:distance)
{
    new Float:HPos[3];
    GetPlayerPos(playerid, HPos[0], HPos[1], HPos[2]);
    for(new i; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(IsPlayerInRangeOfPoint(i, distance, HPos[0], HPos[1], HPos[2]))
            {
                SendClientMessage(i, color, text);
            }
        }
    }
    return 1;
}

stock PlayerIp(playerid)
{
    new Ipas[30];
    GetPlayerIp(playerid, Ipas, 30);
    return Ipas;
}

stock FreezeTemp(playerid, Tempo)
{
    TogglePlayerControllable(playerid, 0);
    SetTimerEx("FreezeTemporario", Tempo, false, "d", playerid);
    return 1;
}

forward FreezeTemporario(playerid);
public FreezeTemporario(playerid)
{
    TogglePlayerControllable(playerid, 1);
    return 1;
}

stock WeaponName(weaponid)
{
    new NameWep[128];
    if(weaponid >= 0 && weaponid <= 40)
    {
        GetWeaponName(weaponid, NameWep, sizeof(NameWep));
    }
    else
    {
        format(NameWep, 128, "Vazio");
    }
    return NameWep;
}

stock KickMessage(playerid, Cor, const text[])
{
    SendClientMessage(playerid, Cor, text);
    SetTimerEx("KickTimer", 3000, false, "d", playerid);
    return 1;
}

stock BanMessage(playerid, Cor, const text[])
{
    SendClientMessage(playerid, Cor, text);
    SetTimerEx("BanTimer", 3000, false, "d", playerid);
    return 1;
}

forward BanTimer(playerid);
public BanTimer(playerid)
{
    return Ban(playerid);
}

forward KickTimer(playerid);
public KickTimer(playerid)
{
    return Kick(playerid);
}

stock PlayerName(playerid)
{
    new NamePlayer[MAX_PLAYER_NAME];
    GetPlayerName(playerid, NamePlayer, sizeof(NamePlayer));
    return NamePlayer;
}

stock Float:GetPlayerSpeedMPH(playerid)
{
    new Float:px, Float:py, Float:pz;
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid), px, py, pz);
    else GetPlayerVelocity(playerid, px, py, pz);
    return floatsqroot(floatpower(floatabs(px), 2.0) + floatpower(floatabs(py), 2.0) + floatpower(floatabs(pz), 2.0)) * 100;
}

stock Float:GetPlayerSpeedKM(playerid)
{
    new Float:ST[4];
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
    else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
    return floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 179.28625;
}

stock MensagemP(const Mensagem[], Float:XPos, Float:YPos, Float:ZPos, cor, Float:raio)
{
    for(new DF; DF < MAX_PLAYERS; DF++)
    {
        if(IsPlayerInRangeOfPoint(DF, raio, XPos, YPos, ZPos))
        {
            SendClientMessage(DF, cor, Mensagem);
        }
    }
    return 1;
}

new VehicleNames[][] =
{
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel",
    "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus",
    "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
    "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection",
    "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus",
    "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie",
    "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral",
    "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder",
    "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van",
    "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale",
    "Oceanic","Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy",
    "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", "Regina", "Comet", "BMX",
    "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper",
    "Rancher", "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking",
    "Blista Compact", "Police Maverick", "Boxville", "Benson", "Mesa", "RC Goblin",
    "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher", "Super GT",
    "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt",
    "Tanker", "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra",
    "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune",
    "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer",
    "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent",
    "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", "Primo",
    "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite",
    "Windsor", "Monster", "Monster", "Uranus", "Jester", "Sultan", "Stratium",
    "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
    "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper",
    "Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400",
    "News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
    "Freight Box", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car",
    "Police Car", "Police Car", "Police Ranger", "Picador", "S.W.A.T", "Alpha",
    "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs", "Boxville",
    "Tiller", "Utility Trailer"
};

stock GetVehicleName(vehicleid)
{
    new String[50];
    if(vehicleid != 0)
    {
        format(String,sizeof(String),"%s",VehicleNames[vehicleid - 400]);
    }
    else
    {
        format(String,sizeof(String),"Vazio");
    }
    return String;
}

stock ClearChat(playerid, bool:Global = false, Quantia = 40)
{
    if(Global == false)
    {
        for(new a = 0; a < Quantia; a++)
        {
            SendClientMessage(playerid, 0xFFFFFFFF, " ");
        }
    }
    else
    {
        for(new a = 0; a < Quantia; a++)
        {
            SendClientMessageToAll(0xFFFFFFFF, " ");
        }
    }
    return 1;
}

stock FormatarGrana(Valor, bool:Sifao = false)
{
    new temp[50],counter = -1;
    valstr(temp,Valor);
    for(new i = strlen(temp);i > 0; i--)
    {
        counter++;
        if(counter == 3)
        {
            strins(temp,".",i);
            counter = 0;
        }
    }
    new VersaoFinal[128];
    if(Sifao == true)
    {
        format(VersaoFinal, sizeof(VersaoFinal), "$%s", temp);
    }
    else
    {
        format(VersaoFinal, sizeof(VersaoFinal), "%s", temp);
    }
    return VersaoFinal;
}
