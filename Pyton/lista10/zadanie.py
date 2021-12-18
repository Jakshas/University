from datetime import date, datetime
from wwo_hist import retrieve_hist_data
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
frequency=24
start_date = '1-AUG-2020'
end_date = '23-NOV-2020'
api_key = '344677d28f294c5fa6001315211712'
location_list = ['wroclaw']

hist_weather_data = retrieve_hist_data(api_key,
                                location_list,
                                start_date,
                                end_date,
                                frequency,
                                location_label = False,
                                export_csv = True,
                                store_df = True)



strconv = lambda x : int(x.replace(' ',''))
zakazenia = pd.read_csv('Zakazenia30323112020.csv', delimiter=';',encoding='windows-1250',converters={'Nowe przypadki' : strconv})
temperatura = pd.read_csv('wroclaw.csv', delimiter=',',encoding='windows-1250',converters={'Nowe przypadki' : strconv})
zakazenia["Date"] = zakazenia["Data"].apply(lambda x : datetime.strptime(x,"%d.%m.%Y").date())
temperatura["date_time"] = temperatura["date_time"].apply(lambda x : datetime.strptime(x,"%Y-%m-%d").date())
poczatek = zakazenia.loc[zakazenia["Date"] >= date(2020,8,1)]

fig, (ax1, ax2) = plt.subplots(1, 2)
locator = mdates.AutoDateLocator()
formatter = mdates.ConciseDateFormatter(locator)
ax1.xaxis.set_major_locator(locator)
ax1.xaxis.set_major_formatter(formatter)
ax2.xaxis.set_major_locator(locator)
ax2.xaxis.set_major_formatter(formatter)
ax1.set_title('Ilosc zakarzen')
ax2.set_title('Temperatura')
ax1.plot("Date","Nowe przypadki",data=poczatek)
ax2.plot("date_time","maxtempC",data=temperatura)

plt.show()