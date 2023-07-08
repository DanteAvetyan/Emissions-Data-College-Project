#include <iostream>
#include <vector>

struct CarbonFootprint
{
public:
	virtual void getCarbonFootprint() {};
};

struct Building : public CarbonFootprint
{
private:
	double emit = 1.004; //lbs CO2 per kWh
public:
	void getCarbonFootprint() override
	{
		std::cout << "Buildings Footprint: " << emit << " lbs CO2 per kWh." << std::endl;
	}

};

struct Car : public CarbonFootprint
{
private:
	double emit = 19.64; //lbs of CO2 per gallon
	int emissions = 6;
public:
	void getCarbonFootprint()
	{
		std::cout << "Car Footprint: " << emit << ". Gas Emissions: " << emissions << " billion metric tons of CO2." << std::endl;
	}

};

struct Bicycle : public CarbonFootprint
{
private:
	double emit = 0.440925; //lbs a mile
	int banana = 65;
	int bacon = 200;
public:
	void getCarbonFootprint()
	{
		std::cout << "Bicycle Footprint: " << emit << "." << banana << "grams of CO2 come from bananas and " << bacon << "grams comes from bacon." << std::endl;
	}

};


int main()
{
	CarbonFootprint go;
	go.getCarbonFootprint();

	std::vector<CarbonFootprint*> point;
	point.reserve(3);
	point.emplace_back(new Building());
	point.emplace_back(new Car());
	point.emplace_back(new Bicycle());

	for (CarbonFootprint* v : point) {
		v->getCarbonFootprint();
	}
}
