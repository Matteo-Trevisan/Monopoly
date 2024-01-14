//
//	AUTORE: Andrea Sacchetto
//

#include "Space/Normal_Space.h"
#include "Space.h"
#include <string>

//Distruttore di default
Normal_Space::~Normal_Space() = default;

//Restituisce il costo del terreno
int Normal_Space::get_terrain_sale_price() const {
	return data.terrain_sale;
}

//Restituisce il costo per la costruzione di una casa
int Normal_Space::get_house_sale_price() const {
	return data.house_sale;
}

//Restituisce il costo per la costruzione di un hotel
int Normal_Space::get_hotel_sale_price() const {
	return data.hotel_sale;
}

//Restituisce il prezzo da pagare se si capita sulla casella in cui è presente una casa
int Normal_Space::get_house_overnight_stay_price() const {
	return data.house_overnight_stay;
}

//Restituisce il prezzo da pagare se si capita sulla casella in cui è presente un hotel
int Normal_Space::get_hotel_overnight_stay_price() const {
	return data.hotel_overnight_stay;
}

//Effettua l'upgrade della tipologia di edificio presente sulla casella. Se empty costruisce una casa
void Normal_Space::upgrade() {
	switch (building) {
		case empty:
			building = Building::house;
			break;
		case house:
			building = Building::hotel;
			break;
		case hotel:
			break;
	}
}

//Metodo che resetta una casella, togliendo edifici e proprietario
void Normal_Space::reset() {
	building = Building::empty;
	owner = nullptr;
}

//In base all'edificio presente sulla casella, viene invocato il rispettivo metodo che restituisce il prezzo da pagare per il pernottamento
int Normal_Space::get_overnight_stay_price() {
	switch (building) {
		case house:
			return get_house_overnight_stay_price();
		case hotel:
			return get_hotel_overnight_stay_price();
		default:
			return 0;
	}
}

//In base all'edificio presente sulla casella, viene invocato il rispettivo metodo che restituisce il prezzo per la costruzione di un edificio di livello successivo
int Normal_Space::get_next_upgrade_price() {
	if (owner != nullptr) {
		switch (building) {
			case empty:
				return get_house_sale_price();
			case house:
				return get_hotel_sale_price();
			case hotel:
				break;
		}
	}
	return 0;
}

//Controlla se è possibile costruire un edificio o migliorarlo
bool Normal_Space::upgradable() {
	return owner != nullptr && building != Building::hotel;
}

//Restituisce il carattere che indica la tipologia di terreno
char Normal_Space::get_type_char() const {
    return data.type;
}

//Restituisce un carattere per indicare la tipologia di edificio presente sulla casella
std::string Normal_Space::get_current_building_char() const {
	switch (building) {
		case house:
			return "*";
		case hotel:
			return "^";
		default:
			return "";
	}
}

//Restituisce il nome dell'edificio che è possibile costruire
std::string Normal_Space::get_next_building_name() const {
	switch (building) {
		case empty:
			return "casa";
		case house:
			return "albergo";
		case hotel:
			return "";
	}
	return "";
}

//Restituisce la tipologia di edificio attualmente presente sulla casella, se presente
Building Normal_Space::get_current_building() const {
	return building;
}
