
# CONSTRUÇÃO DE UMA CÉLULA COMBUSTÍVEL PLANTA MICROBIANA DE BAIXO CUSTO

Trabalho Final de Graduação apresentado
como requisito parcial para obtenção do título
de licenciado em Física, curso de
Licenciatura em Física, Instituto Federal do
Paraná.

Orientadora: Ms. Tunísia Eufrausino Schuler.

Para mais informações ou para visualizar o trabalho completo com a análise de dados e conclusão, envie um email para:
tech.alexp@gmail.com
## Resumo

A demanda por energia vem crescendo no mundo ao mesmo tempo que as
fontes de energia mais utilizadas, os combustíveis fósseis, vêm se tornando escassos.
As fontes renováveis de energia, tais como, solar, eólica e biomassa mostram-se
alternativas limpas, acessíveis e eficientes para a produção da mesma. Diversos
países têm pesquisado uma nova tecnologia alternativa de produção de energia, a
Célula de Combustível Planta-Microbiana (CCPM), que utiliza os processos naturais
de uma planta para a produção de eletricidade, podendo ser a princípio, aplicadas em
telhados verdes e campos de plantação de arroz, fornecendo benefícios além da
produção de energia nestes setores, como a proteção do calor e produção de
alimentos. Neste trabalho, foi construído um protótipo de CCPM utilizando materiais
de baixo custo e uma planta de fácil acesso encontrada em solo brasileiro, a fim de
verificar sua viabilidade, analisando a produção de energia da planta. Foi obtido uma
densidade de corrente de 1,8 mW/m2. A resistência interna da CCPM foi de 1168,5 Ω.
A diferença de potencial máxima de circuito aberto obtida foi de 384,8 mV. Espera-se
que este estudo se torne uma base para estudos mais avançados sobre a CCPM.
## Materiais e Métodos

### Construção do sistema de coleta de dados

Para a coleta de dados da CCPM, foi utilizado o microcontrolador Arduino
MEGA 2560, uma placa protoboard, alguns cabos ou fios para fazer as conexões e
diversos sensores, como o ADS1115 para a coleta de dados de diferença de potencial,
GYML8511 para intensidade da radiação ultravioleta (UV), LDR para intensidade da
luz solar, BME280 para umidade, temperatura e pressão do ar e um sensor de
umidade do solo, conforme mostra a figura.


Sensores e materiais utilizados para o sistema de Arduino.
Fonte: Próprio autor, 2021.

A definição do pino analógico do sensor LDR utilizado no código deve ser ajustado para
o pino A3 para o Arduino UNO, conforme indica a figura 9. Para calcular a irradiância
através do sensor LDR, o valor dado pelo sensor (em lux) através do código é
multiplicado por um fator de conversão, obtido através dos autores Michael et al (2020)
onde para cada 1 W/m² se tem aproximadamente 120 lux.
Utilizando o programa PLX-DAQ para as planilhas do Excel (Parallax, c2021)
em combinação com o circuito de Arduino e sensores, foi possível automatizar a coleta
de dados. O código do programa construído fornece uma linha de dados de hora,
tempo corrido em segundos, data, intensidade UV (mW/m²), voltagem (mV), corrente
(calculada pela divisão da voltagem pela resistência externa dado em mA),
luminosidade (lux), irradiância (W/m²), umidade do solo (%), temperatura do ar (ºC),
pressão (Pa) e umidade do ar (%).

### Construção do cátodo

A CCPM foi composta dos seguintes componentes: planta, ânodo, cátodo, fios
e resistor. O cátodo foi fabricado no laboratório de Física I do Instituto Federal do
Paraná, Campus Foz do Iguaçu. Para sua fabricação seguiu-se o método proposto
por Nulik e Endarko (2016) visando a obtenção deste componente eletrônico,
determinante para a CCPM, com uma condutividade razoável e biocompatibilidade
com a planta.

Primeiramente foi preparado uma mistura de 100ml de cola PVA e 15ml de suco
de limão, todos adicionados a um béquer de 2 litros. Aproximadamente 15ml de água
destilada foi adicionada (apenas para facilitar a agitação) à cola PVA e o suco de limão,
que foram agitados por 20 minutos no agitador magnético ligado na potência de
agitação em 15%, mantendo a mistura aquecida à 150ºC.
Em seguida, adicionou-se 20g de carvão ativado de 50% a 70% de
granulometria menor que 325 mesh, agitando toda a mistura por 1 hora.

O carvão ativado utilizado e a mistura de cola PVA, água destilada, suco de limão e
carvão ativado.
Fonte: Próprio autor, 2021.

Uma malha de aço inoxidável (mesh 100 e fio 0,10mm) foi recortada, com
dimensões de 12 x 16cm ou seja, com aproximadamente 192cm² de área, com as
pontas arredondadas para obter o formato do recipiente da planta.
Seguidamente do preparo da mistura, ela foi aplicada sob a malha do cátodo,
até utilizar toda a mistura disponível no béquer. O cátodo com a mistura foi posto para
secar na estufa à 140°C durante 2 horas, em seguida desligou-se a estufa para deixar
a temperatura diminuir gradualmente até o dia seguinte.

Cátodo após secagem, no dia seguinte.
Fonte: Próprio autor, 2021.

Uma broca de 6mm foi utilizada para fazer vários furos e depois recortado uma
seção de área de aproximadamente 6cm² com uma tesoura, a fim de criar uma
abertura para a passagem da folhagem da planta. Um pequeno furo foi feito no centro
de cada um dos eletrodos para passar um fio de cobre, obtido de uma tomada de
eletrônico comum, que foi soldado para obter o contato entre o eletrodo e o fio.

Cátodo finalizado, com fio conectado e seções de área recortadas. O fio de tomada utilizado
na conexão é mostrado.
Fonte: Próprio autor, 2021

### Construção do ânodo

Uma malha menor (também com pontas arredondadas) foi recortada, contendo
dimensões de 10 x 13cm com 130cm² de área aproximada. Foi utilizado o mesmo
mesh de 100 do cátodo, de fio 10mm.
A broca de 6mm foi utilizada para furar em vários pontos e depois recortar a
seção de área de 6cm² com a tesoura. O furo foi feito no centro para a passagem do
fio conector. O ânodo de malha de aço recortada foi finalizado contendo
aproximadamente 106cm² de área.

Ânodo finalizado.
Fonte: Próprio autor, 2021.

### Construção da CCPM

A planta escolhida é a Allium fistulosum, mais conhecida como cebolinha-verde,
possui folhas finas e alongadas, cilíndricas e fistulosas que crescem entre 30 e 50 cm
de altura, considerada de cultura perene, resistentes ao calor (MACHADO, 2021).
Segundo os autores Santos et al (2020), sob condições favoráveis, a cebolinha pode
obter uma biomassa fresca da raiz de 335,16 kg ha-1 em comparação com valores
produzidos por Helder (2012) com a planta Arundinella anomala de aproximadamente
144 kg ha-1.

A cebolinha utilizada no experimento foi transplantada de um pequeno jardim
doméstico, já em sua fase madura, onde utilizou a mesma terra presente na raiz de
onde foi tirada.

Os 2 recipientes escolhidos para a montagem das duas plantas foram potes de
sorvete de 2 litros reciclados, comumente comercializados, com dimensões de área
da base de 15,5 x 11cm, área da abertura de 18 x 13cm e 10,5cm de altura.

Recipientes para a CCPM e a planta de controle, respectivamente.
Fonte: Próprio autor, 2021.

A CCPM foi montada colocando uma camada de terra de cerca de 25% da
capacidade do recipiente. Em seguida foi incluído o ânodo, plantada as raízes da
cebolinha por dentro das aberturas do eletrodo e completado com terra até sobrar
cerca de 10% do volume do recipiente. Por fim, o cátodo foi incluído, passando as
folhas da planta pelas aberturas e fazendo contato com a terra, completando o
recipiente com água até atingir a base do cátodo. Os eletrodos foram conectados pelo
fio de tomada à um resistor de 100 ohms. O esquema todo segue o seguinte design:

O design escolhido para a CCPM.
Fonte: Próprio autor, 2021.

A CCPM e a planta de controle foram montadas em ambiente doméstico de Foz
do Iguaçu, Paraná, Brasil, onde grande parte da luz do Sol que atingiu a planta se
concentrou no período das 9h até 14h. As plantas foram transplantadas e montadas
no dia 19 de novembro de 2021. Ambas foram regadas sempre no mesmo horário às
19:00h, horário de Brasília, sempre que a umidade do solo atingisse 90% no sensor,
adicionando água até quase encostar visivelmente no cátodo, ou no caso da planta
sem o sistema, até o limite da superfície do solo.

Inicialmente, foi coletado uma série de dados de teste para verificar se a leitura
do sistema do Arduino estava de acordo com valores de um multímetro. Finalmente,
no dia 24 de novembro de 2021, 5 dias após o transplante da planta, foi coletado os
dados da CCPM, de hora em hora, para serem analisados.
## Referências

AHN, J. H. et al. Phylogenetic Diversity of Dominant Bacterial and Archaeal
Communities in Plant-Microbial Fuel Cells Using Rice Plant. 2014. 12f. Artigo. National
Academy of Agricultural Science, Wanju, República da Coreia. Disponível em:
<http://www.jmb.or.kr/journal/viewJournal.html?doi=10.4014/jmb.1408.08053>.
Acesso em 16 mai. 2018.

BORGES, Fernanda F. Uso de “wetland” construído no tratamento de efluente de
ranicultura. 2014. 90f. Tese. Universidade Estadual Paulista (UNESP), Jaboticabal,
Brasil. Disponível em: <http://www.athena.biblioteca.unesp.br/exlibris/bd/cathedra/10-
12-2015/000855097.pdf>. Acesso em: 16 mai. 2018.

CAMPOS, R. M. Sanny e SILVA, P. Vicente. A efetividade do estudo de impacto
ambiental e do licenciamento em projetos de usinas hidrelétrica. Artigo. Instituto de
Geografia, Uberlândia, Brasil. Caminhos de Geografia. Vol. 13, n. 41. 2010. Disponível
em: <https://doaj.org/article/5ed0d668b86641c8848b891474b72aa6>. Acesso em: 23
mai. 2018.

CACPNRJ. Sensor UV ML8511 e Arduino para medidor de intensidade de raios UV.
2021. Cap Sistema. Disponível em:
<https://capsistema.com.br/index.php/2021/03/22/sensor-uv-ml8511-e-arduino-paramedidor-de-intensidade-de-raios-uv/>. Acesso em 20 de out. 2021.

CARMALIN, A. Sophia; SREEJA, S. Green energy generation from plant microbial fuel
cells (PMFC) using compost and a novel clay separator. Sustainable Energy
Technologies and Assessments, India, 2017. Disponível em:
<https://www.sciencedirect.com/science/article/abs/pii/S2213138817302564>.
Acesso em: 5 mar. 2019.

GADGET REBOOT. ADS1115 16 Bit ADC Module with Arduino. YouTube. 2019.
Disponível em: <https://www.youtube.com/watch?v=zl7zJAq9nj8&t=474s>. Acesso
em: 20 de out. 2021.

GADGET REBOOT. Testing the ADS1115 16-bit I2C ADC with Arduino. GitHub. 2019.
Disponível em: <https://github.com/GadgetReboot/ADS1115_Test>. Acesso em: 20 de
out. 2021.

HELDER, M. Design criteria for the Plant-Microbial Fuel Cell. 2012. 161f. Tese de
PhD. Universidade de Wageningen, Wageningen, Holanda. Disponível em:
<http://edepot.wur.nl/239054>. Acesso em: 11 mai. 2018.

LAST MINUTE ENGINEERS. Interface BME280 Temperature, Humidity & Pressure
Sensor with Arduino. c2021. Disponível em:
<https://lastminuteengineers.com/bme280-arduino-tutorial/>. Acesso em 20 de out.
2021.

LEMS S., VAN DER KOOI H.J. e SWAAN ARONS J. The sustainability of resource
utilization. Artigo. Universidade Tecnológica de Delft, Delft, Holanda. Green Chemistry,
vol. 4. 2002. Disponível em: <http://pubs-rscorg.ez109.periodicos.capes.gov.br/en/content/articlepdf/2002/gc/b203490p>. Acesso
em: 24 mai. 2018.

LOGAN, Bruce E. et al. Microbial Fuel Cells: Methodology and Technology. 2006. 12f.
Artigo. Universidade Penn State, Pensilvânia. Universidade de Wageningen,
Wageningen, Holanda. Wetsus, Leeuwarden, Holanda. Universidade de Greifswald,
Soldmannstrasse, Alemanha. Universidade de Queensland, St. Lucia, Austrália.
Universidade de Ghent, Ghent, Bélgica.

MACHADO, M. Santos. Aplicação de silicato de potássio em coentro e cebolinha
sobre estresse salino da solução nutritiva. 2020. 76f. Tese. Universidade Federal do
Ceará, Fortaleza, Brasil. Disponível em: < http://repositorio.ufc.br/handle/riufc/54549>.
Acesso em: 15 de out. 2021.

MYTECTUTOR. Using PLX-DAQ with Arduino. (Getting Started). c2021. Disponível
em: <https://mytectutor.com/using-plx-dax-with-arduino-getting-started/>. Acesso em
20 de out. 2021.

NULIK, B. Willem; ENDARKO. Performance analysis of carbon electrode synthesized
with poly (vinyl alcohol) and citric acid as cross-linking agent for desalination of NaCl
solution in capacitive deionization. 2016. 5f. Artigo. Institut Teknologi Sepuluh
Nopember, East Java, Indonesia. Disponível em: <
https://www.researchgate.net/publication/312155166_Performance_analysis_of_carb
on_electrode_synthesized_with_poly_vinyl_alcohol_and_citric_acid_as_crosslinking_agent_for_desalination_of_NaCl_solution_in_capacitive_deionization?_sg=c
PDdYLMd3y7OjfOEcHkXGfo7UBKjTdVH_FPSeeR1gqp0GhxdjxyCZetNOpKjV2IDYv
ZdxhSh2sXndTr174Pjfw>. Acesso em: 14 set. 2021.

RJLOURA. Arduino moisture analog with nano. 2017. GITHUB. Disponível em: <
https://github.com/rjloura/Arduino/commit/2ae6df769d0181e7d8fff3df8ae1d79f2efdf2
0f >. Acesso em: 20 de out. 2021

SANTOS, M. A. Lins et al. Desempenho agronômico e analise multivariada na
produção da cebolinha verde em resposta a lâminas de irrigação e níveis de adubação
sintética. 2020. 24f. Artigo. Universidade Federal de Alagoas, Brasil. Disponível em: <
https://www.researchgate.net/publication/347801621_Desempenho_agronomico_e_a
nalise_multivariada_na_producao_da_cebolinha_verde_em_resposta_a_laminas_de
_irrigacao_e_niveis_de_adubacao_sintetica>. Acesso em: 15 de out. 2021.

SARMA, J. Pranab; MOHANTY, Kaustubha. Epipremnum aureum and Dracaena
braunii as indoor plants for enhanced electricity generation in a plant microbial fuel cell
with electrochemical modified carbon fiber brush anode. 2018. 7f. Artigo. Instituto
Indiano de Tecnologia de Guwahati, Guwahati, India. Disponível em:
<https://www.sciencedirect.com/science/article/abs/pii/S1389172317309854>.
Acesso em: 22 nov. 2021.

SCIENCE DAILY. Figura 1 - CCPM. Disponível em:
<https://www.sciencedaily.com/images/2012/11/121123092129_1_900x600.jpg>.
Acesso em: 15 mai. 2018.

STRIK, David P. B. T. B. et al. Green electricity production with living plants and
bacteria in a fuel cell. 2008. 7f. Short Communication. Universidade de Wageningen,
Wageningen, Holanda. Disponível em:
<https://pt.scribd.com/document/373543609/Green-electricity-production-with-livingplants-and-bacteria-in-a-fuel-cell-pdf>. Acesso em: 15 mai. 2018.

STRIK, David P. B. T. B. et al. Microbial solar cells: applying photosynthetic and
electrochemically active organisms. 2010. 29f. Artigo. Universidade de Wageningen,
Wageningen, Holanda. Disponível em:
https://www.cell.com/trends/biotechnology/abstract/S0167-7799(10)00175-7. Acesso
em: 15 mai. 2018.

THOMAZ, Sidinei M. et al. Aquatic Macrophytes of Itaipu Reservoir, Brazil: Survey of
Species and Ecological Consideration. 1998. 8f. Artigo. Universidade Estadual de
Maringá, Maringá. Universidade Federal de Goiás, Goiânia, Brasil. Disponível em:
<http://www.scielo.br/pdf/babt/v42n1/v42n1a03.pdf>. Acesso em: 16 mai. 2018.

TIMMERS, Ruud A. et al. Long-term performance of a plant microbial fuel cell with
Spartina anglica. 2010. 9f. Artigo. Universidade de Wageningen, Wageningen,
Holanda. Disponível em: <https://www.ncbi.nlm.nih.gov/pmc/articles/PMC2841269/>.
Acesso em: 15 mai. 2018.

VAN SARK, G. J. H. M. Willfried. Teaching the relation between solar cell efficiency
and annual energy yield. Artigo. Universidade Utrecht, Heidelberglaan, Holanda.
European Journal of Physics. Vol. 28. 2007. Disponível em:
<stacks.iop.org/EJP/28/415>. Acesso em: 23 mai. 2018.

VIANA, C. Correia. Utilizando o Sensor de Luminosidade LDR no Arduino. Blog da
Robótica. 2020. Disponível em: <
https://www.blogdarobotica.com/2020/09/29/utilizando-o-sensor-de-luminosidade-ldrno-arduino/>. Acesso em: 20 de out. 2021

YANG, Jin e CHEN, Ben. Emergy-based sustainability evaluation of wind power
generation systems. Artigo. Universidade de Geociência da China, Pequim, China.
Applied Energy, vol. 177. 2016. Disponível em: <https://ac.elscdn.com/S0306261916307310/1-s2.0-S0306261916307310-
main.pdf?_tid=22c41785-a057-40a3-a7e0-
3cfddaa07edb&acdnat=1527193006_1188ec31ab1c25745c42e3f1002c6b01>.
Acesso em: 24 mai. 2018