¡Hola! Encantado de ayudarte. Este script en Bash está diseñado para **mostrar un resumen del estado del sistema** en un sistema Linux (Debian en tu caso). Muestra información sobre el hardware, la memoria, el uso del disco, la red y algunas estadísticas de uso del sistema. Vamos a desglosarlo **línea por línea** para que lo comprendas **de manera profunda y clara**.

---

## 🟩 1. **Encabezado del script**

```bash
#!/bin/bash
```

Este "shebang" le dice al sistema que este script debe ejecutarse usando el intérprete de comandos **Bash**.

---

## 🟩 2. **Arquitectura del sistema**

```bash
arch=$(uname -a)
```

- `uname -a`: muestra toda la información del sistema (kernel, arquitectura, nombre del host, etc.).
- `arch=...`: guarda esa información en una variable llamada `arch`.

🧠 **¿Qué obtienes?** Algo como:  
`Linux debian 5.10.0-22-amd64 ... x86_64 GNU/Linux`

---

## 🟩 3. **CPU física y virtual**

```bash
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
```

- `/proc/cpuinfo`: contiene información de la CPU.
- `grep "physical id"`: busca el ID físico de cada CPU.
- `sort -u`: elimina duplicados.
- `wc -l`: cuenta cuántas CPUs físicas hay.

```bash
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)
```

- Busca cuántos *núcleos lógicos* hay (vCPUs).  
- `processor` aparece una vez por cada hilo/núcleo.

🧠 **Ejemplo**: Si tienes un procesador con 2 núcleos físicos con hyperthreading, verás 2 CPUs físicas y 4 vCPUs.

---

## 🟩 4. **Uso de la memoria RAM**

```bash
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
```

- `free --mega`: muestra el uso de RAM en MB.
- `awk`: filtra y calcula los valores:
  - `$2`: total.
  - `$3`: usado.
  - `$3/$2*100`: porcentaje de uso.

🧠 Ejemplo de salida de `free --mega`:
```
              total        used        free
Mem:           7973        2531        1843
```

---

## 🟩 5. **Uso del disco**

```bash
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
```

- `df -m`: muestra uso del disco en MB.
- `grep "/dev/"`: filtra los discos reales.
- `grep -v "/boot"`: excluye la partición `/boot`.
- `awk`: suma el espacio total de todas las particiones.

```bash
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')
```

- Suma el espacio usado (`$3`) y calcula el porcentaje de uso (`$3/$2`).

---

## 🟩 6. **Carga de la CPU (CPU load)**

```bash
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
```

- `vmstat 1 2`: muestra estadísticas del sistema cada 1 segundo, dos veces.
- La **segunda línea** es más precisa.
- `$15`: porcentaje de **CPU libre (idle)**.
- Luego:

```bash
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)
```

- Se resta del 100% para obtener **uso actual de CPU**.

---

## 🟩 7. **Último arranque del sistema**

```bash
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
```

- `who -b`: muestra cuándo se inició el sistema por última vez.
- `awk`: extrae la fecha y hora.

🧠 Ejemplo:  
`system boot  2025-04-28 08:52`

---

## 🟩 8. **Uso de LVM (Logical Volume Manager)**

```bash
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
```

- `lsblk`: lista dispositivos de bloque (discos/particiones).
- `grep "lvm"`: busca si se está usando LVM.
- Devuelve `yes` o `no`.

---

## 🟩 9. **Conexiones TCP activas**

```bash
tcpc=$(ss -ta | grep ESTAB | wc -l)
```

- `ss -ta`: muestra todas las conexiones TCP activas.
- `grep ESTAB`: filtra las que están "ESTABLISHED".
- `wc -l`: cuenta cuántas hay.

---

## 🟩 10. **Usuarios conectados**

```bash
ulog=$(users | wc -w)
```

- `users`: muestra los usuarios conectados.
- `wc -w`: cuenta cuántos hay.

---

## 🟩 11. **Red (IP y MAC)**

```bash
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
```

- `hostname -I`: devuelve la IP de la máquina.
- `ip link`: muestra interfaces de red.
- `grep "link/ether"`: busca la dirección MAC.
- `awk '{print $2}'`: extrae la MAC.

---

## 🟩 12. **Comandos sudo ejecutados**

```bash
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
```

- `journalctl`: consulta logs del sistema.
- `_COMM=sudo`: busca entradas del comando `sudo`.
- `grep COMMAND`: filtra los logs donde se ejecutó un comando con `sudo`.
- `wc -l`: cuenta cuántos se han hecho.

---

## 🟩 13. **Mostrar toda la información**

```bash
wall " ... "
```

- `wall`: muestra un mensaje a **todos los usuarios conectados**.
- Dentro del mensaje, se muestran todas las variables calculadas antes.

🧠 Por ejemplo, puede mostrar algo como:

```
Architecture: Linux debian 5.10.0-22-amd64 ...
CPU physical: 1
vCPU: 2
Memory Usage: 2531/7973MB (31.74%)
Disk Usage: 12345/25000 (49%)
CPU load: 12.3%
Last boot: 2025-04-28 08:52
LVM use: yes
Connections TCP: 10 ESTABLISHED
User log: 2
Network: IP 192.168.1.10 (aa:bb:cc:dd:ee:ff)
Sudo: 5 cmd
```

---

## ✅ Resumen de qué hace el script

- Mide el **estado actual** del sistema: hardware, recursos, conexiones, red y seguridad.
- Está pensado como un **informe rápido y útil** para administradores del sistema.
- Utiliza herramientas estándar de Linux: `grep`, `awk`, `df`, `free`, `ss`, `journalctl`, etc.
- No requiere permisos especiales, salvo para el uso de `journalctl` (puede necesitar sudo si no está en grupo `adm`).

---

¿Quieres que prepare una versión mejorada del script con colores o exportando los datos a un archivo?
