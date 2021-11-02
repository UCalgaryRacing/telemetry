#
# AUTO-GENERATED Makefile; do not edit, changes will be lost
#

# Define target type
TARGET:=wp85

# Custom makefile include: initialization
-include ../customInit.mk

# Only when not cleaning
ifneq ($(MAKECMDGOALS),clean)
endif

# Target artifact.*
TARGET_ARTIFACT:=env_test_yellow.$(TARGET).update

# Clean command
CLEANCOMMAND:=find -maxdepth 1 -mindepth 1 ! -name Makefile ! -name .rsync-rules -exec rm -R {} \;

# MK command
MKCOMMAND:=cd ..;mksys $(MKSYS_FLAGS) -t $(TARGET) -o Target_Legato_Debug -w Target_Legato_Debug --cflags=-O2 --object-dir=build/$@ --output-dir=$(UPDATE_FILE_DIR) -i "$(LEGATO_ROOT)/interfaces/positioning" -i "$(LEGATO_ROOT)/interfaces/secureStorage" -i "$(LEGATO_ROOT)/interfaces/modemServices" -i "$(LEGATO_ROOT)/interfaces/wifi" -i "$(LEGATO_ROOT)/interfaces/airVantage" -i "$(LEGATO_ROOT)/interfaces/watchdog" -i "$(LEGATO_ROOT)/interfaces/atServices" -i "$(LEGATO_ROOT)/interfaces/logDaemon" -i "$(LEGATO_ROOT)/interfaces" -i "$(LEGATO_ROOT)/interfaces/supervisor" -i "$(LEGATO_ROOT)/interfaces/portService" -i "$(LEGATO_ROOT)/interfaces/airVantage/legacy" -s "apps/ArduinoBridge" -s "apps/BluetoothServices" -s "$(LEGATO_ROOT)/apps/platformServices/airVantageConnector" -s "apps/YellowSensor/components/sensors" -s "$(LEGATO_ROOT)/components/airVantage" -s "apps/Telemetry" -s "$(LEGATO_ROOT)/apps/platformServices/airVantage" -s "samples/tutorials/mangOH_Red/gpio/Cf3GpioControl" -s "apps/YellowOnBoardActuators/components" -s "apps/Welcome/components" -s "samples/tutorials/mangOH_Red/gpio/TimerLed" -s "samples/tutorials/mangOH_Green/gpio/Cf3GpioControl" -s "apps/test/YellowEnvironment" -s "$(LEGATO_ROOT)/components/portService" -s "$(LEGATO_ROOT)/components/modemServices/platformAdaptor/default" -s "apps/LedService" -s "samples/tutorials/mangOH_Red/gpio/TouchSensor" -s "samples/tutorials/mangOH_Green/i2c/BatteryChargerReading" -s "$(LEGATO_ROOT)/components/audio/platformAdaptor/default" -s "samples/Demos/MobileAssetTracker" -s "$(LEGATO_ROOT)/components/3rdParty" -s "samples/tutorials/mangOH_Green/adc/NoiseSensor" -s "samples/BluetoothSensorTag" -s "$(LEGATO_ROOT)/components/fwupdate/platformAdaptor/default" -s "$(LEGATO_ROOT)/components/dataConnectionService" -s "$(LEGATO_ROOT)/components/airVantage/platformAdaptor/default" -s "apps/DataHub/components" -s "samples/Demos/WiredSensor" -s "apps/NtagDhubIf" -s "apps/MuxControl/tools" -s "components" -s "samples/tutorials/mangOH_Red/AirVantage/ButtonToAirVantage" -s "$(LEGATO_ROOT)/components/positioning/platformAdaptor/default" -s "samples/Demos/KillSwitch" -s "$(LEGATO_ROOT)/apps/proprietary/atAirVantage/bin/$(TARGET)" -s "$(LEGATO_ROOT)/components/devMode" -s "$(LEGATO_ROOT)/apps/proprietary/qmiAirVantage/bin/$(TARGET)" -s "$(LEGATO_ROOT)/components/modemServices" -s "apps/OpenWeatherMapAmbientTemperature" -s "apps/YellowSensor/components" -s "apps/SocialService" -s "apps/DataHub-Buzzer" -s "apps/DataHub/test" -s "$(LEGATO_ROOT)/components/dataConnectionService/platformAdaptor/default" -s "apps/MqttClient" -s "apps/RedSensorToCloud/components" -s "apps/VegasMode" -s "$(LEGATO_ROOT)/modules/WiFi/apps/tools/wifi" -s "samples/RelayControl" -s "samples/Demos/LegatoWebsocketd" -s "samples/BsecTest" -s "apps/locationService" -s "$(LEGATO_ROOT)/components/positioning" -s "samples/Demos/GpsPublish" -s "samples/tutorials/voice" -s "$(LEGATO_ROOT)/components/secStore" -s "$(LEGATO_ROOT)/components/uartMode/platformAdaptor/default" -s "apps/BatteryService" -s "samples/IioDeviceList" -s "samples/Demos/CheckState" -s "apps/GpioExpander/gpioExpanderService" -s "$(LEGATO_ROOT)/apps/tools" -s "apps/Bme680EnvironmentalSensor" -s "$(LEGATO_ROOT)/apps/proprietary/atQmiLinker/bin/$(TARGET)" -s "$(LEGATO_ROOT)/modules/WiFi/service" -s "samples/BatteryClient" -s "$(LEGATO_ROOT)/components/fwupdate" -s "apps/RedSensorToCloud/components/sensors" -s "apps/GpioExpander/gpioExpanderDemo" -s "apps/DataRouter" -s "apps/DataRouter/drTool" -s "$(LEGATO_ROOT)/components/secStore/platformAdaptor/default" -s "samples/tutorials/mangOH_Green/gpio/TimerLed" -s "$(LEGATO_ROOT)/components/atServices" -s "$(LEGATO_ROOT)/components/uartMode" -s "$(LEGATO_ROOT)/components" -s "samples/tutorials/mangOH_Red/i2c/BatteryChargerReading" -s "samples/tutorials/mangOH_Green/gpio/TouchSensor" -s "apps/Heartbeat" -s "samples/tutorials/developerDay2016/components" -s "samples/tutorials/mangOH_Red/adc/NoiseSensor" -s "$(LEGATO_ROOT)/apps/platformServices" -s "apps/ntag" -s "apps/MuxControl/muxCtrlService" -s "samples/Demos/ShakeNWake" -C -g -X -g -L -g env_test_yellow.sdef

# Custom makefile include: definitions
-include ../customDefs.mk

.PHONY: all target clean codegen mkCodegen systocwe

all: target systocwe

codegen: mkCodegen

mkCodegen:
	$(MKCOMMAND) --generate-code

target:
	$(MKCOMMAND)

systocwe:
	systocwe $(TARGET) $(TARGET_ARTIFACT) cwe


clean:
	$(CLEANCOMMAND)


# Custom makefile include: targets
-include ../customTargets.mk
