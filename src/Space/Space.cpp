//
//	AUTORE: Andrea Sacchetto
//

#include "Space/Space.h"

//Essendo Space una "classe base", la maggior parte dei metodi in questa classe sono virtuali e verranno
//quindi sovrascritti nelle relative classi derivate

//Costruttore della classe Space
Space::Space(const std::string& name, Player* owner) : name(name), owner(owner) {}

//Distruttore di default
Space::~Space() = default;

//Restituisce un valore di default per il costo del terreno
int Space::get_terrain_sale_price() const {
	return 0;
}

//Restituisce il costo di default per la costruzione di una casa
int Space::get_house_sale_price() const {
	return 0;
}

//Restituisce un valore di default per il costo di costruzione di un hotel
int Space::get_hotel_sale_price() const {
	return 0;
}

//Restituisce un prezzo di default da pagare se si capita sulla casella in cui è presente una casa
int Space::get_house_overnight_stay_price() const {
	return 0;
}

//Restituisce un prezzo di default da pagare se si capita sulla casella in cui è presente un hotel
int Space::get_hotel_overnight_stay_price() const {
	return 0;
}

//Restituisce un prezzo di default per il costo di soggiorno
int Space::get_overnight_stay_price() {
	return 0;
}

//Restituisce un prezzo di default per edificare o edificare al livello successivo
int Space::get_next_upgrade_price() {
	return 0;
}

//Imposta a un valore di default la possibilità di costruire un edificio o migliorarlo
bool Space::upgradable() {
	return false;
}

//Metodo che effettua l'upgrade dell'edificio, se presente. Altrimenti viene costruita una casa
void Space::upgrade() {

}

//Metodo che effettua il reset delle proprietà della casella
void Space::reset() {

}

//Restituisce un valore di default per il carattere che indica la tipologia di terreno
char Space::get_type_char() const {
	return ' ';
}

//Restituisce un valore di default per la tipologia di edificio presente sulla casella
std::string Space::get_current_building_char() const {
	return "";
}

//Restituisce un valore di default per la tipologia di edificio che è possibile edificare sulla casella
std::string Space::get_next_building_name() const {
	return "";
}

//Restituisce un valore di default che identifica l'ammontare di denaro da ricevere al passaggio del VIA
int Space::get_start_pass_money() const {
	return 0;
}

//Ritorna il nome della casella
std::string Space::get_name() const {
	return name;
}

//Imposta il nome della casella con il valore passatogli come parametro
void Space::set_name(const std::string& value) {
	name = value;
}

//Restituisce la variabile che identifica il proprietario della casella
Player *Space::get_owner() {
	return owner;
}

//Assegna alla variabile che identifica il proprietario della casella con il valore passatogli come parametro
void Space::set_owner(Player* p) {
	owner = p;
}

//Ritorna un valore di default come attuale edificio sulla casella
Building Space::get_current_building() const {
	return Building::empty;
}

//Viene sovrascritto l'operatore <<
std::ostream &operator<<(std::ostream &os, const Space &d) {
	return os << d.get_type_char();
}

