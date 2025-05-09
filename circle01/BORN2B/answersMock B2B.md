# 🐧 **Resumen de Conceptos de Linux/Debian**

---

## 📌 Comparación: **Debian vs CentOS (Rocky)**

* Ambos tienen aplicaciones similares.
* **Debian** es más *beginner friendly* (más fácil para principiantes).
* **Rocky** (basado en RHEL) está más orientado a empresas:

  * Soporte de mayor duración.
  * Diferente gestor de paquetes.

---

## 💻 ¿Para qué sirven las máquinas virtuales?

* Simulan un sistema de computación real.
* Ejecutan programas como si fuesen una computadora física.
* Permiten:

  * Múltiples entornos en un solo hardware.
  * Aislamiento del sistema operativo y hardware físico.
* Objetivo: ofrecer un entorno de ejecución **independiente** de la plataforma.

---

## 🔍 ¿Qué hace tu máquina virtual?

* No hace nada, solo **entrega datos cada 10 minutos**.

---

## 🔐 ¿Qué es **SSH**? ¿Ventajas?

* **Secure Shell**: protocolo para conexión remota segura a través de una red.
* Usos:

  * Acceso remoto a terminales.
  * Automatización y scripting.
* Ventajas:

  * Cifrado fuerte.
  * Encriptación clave pública / clave privada.
  * Alta seguridad.

---

## 🧑‍💻 ¿Qué es **sudo**? ¿Ventajas?

* Abreviatura de **superuser do**.
* Permite ejecutar comandos como **superusuario (root)** sin iniciar sesión como root.
* Funcionamiento:

  1. Verifica permisos.
  2. Pide la contraseña del usuario (no la de root).
  3. Ejecuta el comando con privilegios elevados.
* Ventajas:

  * Más control y trazabilidad.
  * Seguridad granular.
  * Registra los comandos ejecutados.

---

## 🔥 ¿Qué es **UFW**? ¿Ventajas?

* **Uncomplicated Firewall**: herramienta de configuración de firewall.
* Simplifica el uso de **iptables**.
* Ventajas:

  * Sintaxis clara y amigable.
  * Alta compatibilidad.
  * Ideal para usuarios sin experiencia avanzada en redes.

---

## ⏲️ ¿Qué es **crontab**?

* Herramienta para programar tareas automáticas en intervalos definidos.
* Funciona junto con el demonio **cron**.

### Parámetros de `crontab`:

| Campo     | Significado                                 |
| --------- | ------------------------------------------- |
| `m`       | Minuto (0–59)                               |
| `h`       | Hora (0–23) en formato 24 horas             |
| `dom`     | Día del mes (1–31)                          |
| `dow`     | Día de la semana (0–7 o `mon`, `tue`, etc.) |
| `user`    | Usuario que ejecutará el comando            |
| `command` | Comando o ruta del script a ejecutar        |

---

## ⚙️ Diferencias: `apt` vs `aptitude` vs `AppArmor`

* **APT**: Gestor de paquetes de bajo nivel.
* **Aptitude**: Herramienta más avanzada con mejor funcionalidad.
* **AppArmor**:

  * Módulo de seguridad del kernel.
  * Restringe capacidades de los programas según su perfil.

---

## 🔁 Recomendaciones

* ✅ **Clonar el archivo `.vdi` antes de hacer correcciones.**
* 📚 **Estudiar los comandos.**

---

## 👤 Usuarios y Grupos

```bash
sudo adduser nombre_usuario         # Crear usuario con /home
sudo addgroup nombre_grupo          # Crear nuevo grupo
sudo adduser usuario grupo          # Añadir usuario a grupo
groups nombre_usuario               # Ver grupos de un usuario
sudo deluser nombre_usuario         # Eliminar usuario
sudo delgroup nombre_grupo          # Eliminar grupo
sudo ufw allow (portnumber)			# permitir puerto
sudo ufw status 
```

---

## 🖥️ Cambiar el nombre del hostname

```bash
sudo nano /etc/hostname             # Cambia el nombre directamente
sudo nano /etc/hosts                # Cambia el nombre en esta línea:
                                   # 127.0.1.1   old-hostname
sudo reboot                         # Reinicia para aplicar cambios
```

---

## 🕒 Modificar ejecución del script de cada 10 a cada 30 minutos

```bash
crontab -e
# Cambiar la línea:
*/10 * * * * /ruta/al/script.sh
# Por:
*/30 * * * * /ruta/al/script.sh
```

---

¿Te gustaría que te genere una versión imprimible o en PDF?


