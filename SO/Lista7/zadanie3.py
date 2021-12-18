import psutil

ps = psutil.pids()

sumaRSS = 0
sumaSize = 0
for i in ps:
    p = psutil.Process(i)
    meminfo = p.memory_full_info()
    sumaRSS = sumaRSS + meminfo.rss
    sumaSize = sumaSize + meminfo.vms

print("VMSize"+sumaSize)
print("VMRSS"+sumaRSS)