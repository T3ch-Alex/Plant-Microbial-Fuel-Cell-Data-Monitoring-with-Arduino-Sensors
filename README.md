# CONSTRUCTION OF A LOW COST MICROBIAL PLANT FUEL CELL

Final Graduation Work presented
as a partial requirement for obtaining the title
degree in Physics, course in
Degree in Physics, Federal Institute of
Paraná.

Advisor: Ms. Tunisia Eufrausino Schuler.

For more information or to view the complete work with data analysis and conclusion, send an email to:
tech.alexp@gmail.com

# Summary

The demand for energy has been growing in the world at the same time that the most used energy sources, 
fossil fuels, have become scarce. Renewable energy sources, such as solar, wind and biomass, are clean, 
accessible and efficient alternatives for energy production. Several countries have been researching a 
new alternative energy production technology, the Plant-Microbial Fuel Cell (PMFC), which uses the natural 
processes of a plant to produce electricity, and can be, in principle, applied to green roofs and fields of 
rice plantation, providing benefits beyond energy production in these sectors, such as heat protection and 
food production. In this work, a PMFC prototype was built using low cost materials and an easily accessible 
plant found in Brazilian soil, in order to verify its viability, analyzing the plant's energy production. 
A current density of 1.8 mW/m2 was obtained. The PMFC internal resistance was 1168.5 Ω. 
The maximum open-circuit potential difference obtained was 384.8 mV. It is hoped that this study will become
 a foundation for more advanced studies on PMFC.

## Materials and methods

### Construction of the data collection system

For PMFC data collection, an Arduino MEGA 2560 microcontroller was used, a protoboard, some cables or wires 
to make the connections and several sensors, such as the ADS1115 for potential difference data collection, 
GYML8511 for radiation intensity ultraviolet (UV), LDR for sunlight intensity, BME280 for humidity, 
temperature and air pressure, and a soil moisture sensor, as shown in the figure.

![Screenshot_1](https://user-images.githubusercontent.com/108704114/209579089-26262f73-09c7-4467-9305-095fb1f0870d.png)

*Sensors and materials used for the Arduino system.
Source: Author himself, 2021.*

All were connected to the PMFC according to the following scheme:

![Screenshot_2](https://user-images.githubusercontent.com/108704114/209579397-86649111-ab8f-42c4-94e3-67aae61facb8.png)

*PMFC circuit diagram with Arduino and Sensors.
Source: Author himself, 2021.*

The analog pin definition of the LDR sensor used in the code must be set to pin A3 for the Arduino UNO. 
To calculate the irradiance through the LDR sensor, the value given by the sensor (in lux) through the code 
is multiplied by a conversion factor, obtained through the authors Michael et al (2020) where for every 
1 W/m² there is approximately 120 lux.
Using the PLX-DAQ program for Excel spreadsheets (Parallax, c2021) in combination with the Arduino circuit 
and sensors, it was possible to automate data collection. The constructed program code provides a line of 
time data, elapsed time in seconds, date, UV intensity (mW/m²), voltage (mV), current (calculated by dividing 
the voltage by the external resistance given in mA), luminosity ( lux), irradiance (W/m²), soil moisture (%), 
air temperature (ºC), pressure (Pa) and air humidity (%).

### Construction of the cathode

The PMFC was composed of the following components: plant, anode, cathode, wires and resistor. The cathode 
was manufactured in the Physics I laboratory of the Federal Institute of Paraná, Campus Foz do Iguaçu. 
For its manufacture, the method proposed by Nulik and Endarko (2016) was followed in order to obtain this 
electronic component, which is decisive for PMFC, with reasonable conductivity and biocompatibility with 
the plant.

First, a mixture of 100ml of PVA glue and 15ml of lemon juice was prepared, all added to a 2-liter beaker. 
Approximately 15ml of distilled water was added (just to facilitate stirring) to the PVA glue and lemon 
juice, which were stirred for 20 minutes on a magnetic stirrer turned on at 15% stirring power, keeping 
the mixture heated at 150°C.
Then, 20g of activated carbon of 50% to 70% of granulometry smaller than 325 mesh was added, stirring the 
whole mixture for 1 hour.

![Screenshot_3](https://user-images.githubusercontent.com/108704114/209579093-5b425104-0663-4d5f-8f85-04339d318270.png)

*The activated carbon used and the mixture of PVA glue, distilled water, lemon juice and activated carbon.
Source: Author himself, 2021.*

A stainless steel mesh (mesh 100 and wire 0.10 mm) was cut, measuring 12 x 16 cm, that is, approximately 
192 cm² in area, with rounded ends to obtain the shape of the plant container. After preparing the mixture, 
it was applied under the cathode mesh, until all the mixture available in the beaker was used. The cathode 
with the mixture was placed to dry in the oven at 140°C for 2 hours, then the oven was turned off to let the 
temperature gradually decrease until the next day.

![Screenshot_4](https://user-images.githubusercontent.com/108704114/209579094-3642d322-4210-4279-8eb0-ddc5c911cfd8.png)

*Cathode after drying, the next day.
Source: Author himself, 2021.*

A 6mm drill was used to make several holes and then a section of approximately 6cm² was cut with scissors, 
in order to create an opening for the passage of the plant's foliage. A small hole was made in the center 
of each of the electrodes to pass a copper wire, obtained from a common electronic plug, which was soldered 
to obtain contact between the electrode and the wire.

![Screenshot_5](https://user-images.githubusercontent.com/108704114/209579095-4f475101-9d34-499c-86fd-421907a5aecf.png)

*Finished cathode, with wire attached and area sections cut out. The plug wire used in the connection is shown.
Source: Author himself, 2021.*

### Construction of the anode

A smaller mesh (also with rounded ends) was cut, containing dimensions of 10 x 13cm with an approximate area 
of 130cm². The same 100 mesh of the cathode was used, with 10mm wire. The 6mm drill bit was used to drill at 
several points and then cut out the 6cm² area section with scissors. A hole was made in the center for the 
passage of the connecting wire. The cut steel mesh anode was finished containing approximately 106cm² in area.

![Screenshot_6](https://user-images.githubusercontent.com/108704114/209579097-fc55c903-aa61-4d40-bfcb-4781400a28bf.png)

*Finished anode.
Source: Author himself, 2021.*

### Construction of the PMFC

The plant chosen is Allium fistulosum, better known as chives-green, it has thin and elongated, cylindrical 
and fistulous leaves that grow between 30 and 50 cm in height, considered a perennial crop, resistant to 
heat (MACHADO, 2021).

According to authors Santos et al (2020), under favorable conditions, chives can obtain a fresh root biomass 
of 335.16 kg ha-1 compared to values produced by Helder (2012) with the Arundinella anomala plant of 
approximately 144 kg ha-1.

The chives used in the experiment were transplanted from a small domestic garden, already in their mature 
phase, where they used the same earth present in the root from which they were taken.

The 2 containers chosen for assembling the two plants were 2-liter recycled ice cream pots, commonly sold, 
with base area dimensions of 15.5 x 11 cm, opening area of 18 x 13 cm and height of 10.5 cm.

![Screenshot_7](https://user-images.githubusercontent.com/108704114/209579099-f1a4cc00-6f1b-4284-aa28-e93330b80330.png)

*Containers for PMFC and control plant, respectively.
Source: Author himself, 2021.*

The PMFC was assembled by placing a layer of earth of about 25% of the capacity of the container. 
Then the anode was included, the chive roots were planted inside the electrode openings and filled with 
soil until about 10% of the container volume remained. Finally, the cathode was included, passing the 
leaves of the plant through the openings and making contact with the earth, filling the container with 
water until reaching the base of the cathode. The electrodes were connected by the plug wire to a 100 ohm 
resistor. The whole scheme follows this design:

![Screenshot_8](https://user-images.githubusercontent.com/108704114/209579101-7238aec9-677a-4562-b441-af91f00978f0.png)

*Chosen design for the PMFC.
Source: Author himself, 2021.*

The PMFC and the control plant were set up in a domestic environment in Foz do Iguaçu, Paraná, Brazil, 
where most of the sunlight that reached the plant was concentrated in the period from 9 am to 2 pm. The 
plants were transplanted and mounted on November 19, 2021. Both were always watered at the same time at 
7:00 pm, Brasília time, whenever the soil moisture reached 90% on the sensor, adding water until it almost 
visibly touched the cathode , or in the case of the plant without the system, up to the limit of the soil 
surface.

Initially, a series of test data was collected to verify if the reading of the Arduino system was in 
accordance with the values of a multimeter. Finally, on November 24, 2021, 5 days after transplanting 
the plant, hourly PMFC data were collected for analysis.