const express = require('express');
const path = require('path');
const mqtt = require('mqtt');
const http = require('http');
const { Server } = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = new Server(server);
const PORT = 3000;

// Conexión al broker MQTT
const client = mqtt.connect('mqtt://test.mosquitto.org');

// Confirmar conexión
client.on('connect', () => {
  console.log('✅ Conectado al broker MQTT');
  client.subscribe('codigo/sensor', (err) => {
    if (!err) {
      console.log('📡 Suscrito a codigo/sensor');
    }
  });
});

// Recibir mensajes MQTT
client.on('message', (topic, message) => {
  const msg = message.toString();
  console.log(`📥 Mensaje en ${topic}: ${msg}`);
  // Enviar mensaje al frontend via WebSocket
  io.emit('sensorData', msg);
});

// Middleware para servir HTML
app.use(express.static(path.join(__dirname, 'public')));

// Rutas para publicar ON/OFF
app.get('/on', (req, res) => {
  client.publish('codigo/relay', 'ON');
  console.log('📤 Publicado: ON');
  res.send('Mensaje ON enviado al tópico codigo/relay');
});

app.get('/off', (req, res) => {
  client.publish('codigo/relay', 'OFF');
  console.log('📤 Publicado: OFF');
  res.send('Mensaje OFF enviado al tópico codigo/relay');
});

// Arrancar servidor
server.listen(PORT, () => {
  console.log(`🚀 Servidor corriendo en http://localhost:${PORT}`);
});
