[{"id":"a400a6e7.e01ea8","type":"tab","label":"Flow 1","disabled":false,"info":""},{"id":"e4fa5786.3c4ad8","type":"mqtt in","z":"a400a6e7.e01ea8","name":"","topic":"room/IR","qos":"2","datatype":"auto","broker":"f3ec7454.63e1f8","x":190,"y":400,"wires":[["17d08f88.c9673"]]},{"id":"6838d67d.b74c38","type":"ui_text","z":"a400a6e7.e01ea8","group":"7499c6af.dc19e8","order":0,"width":0,"height":0,"name":"","label":"IR Status","format":"{{msg.payload}}","layout":"row-spread","x":640,"y":220,"wires":[]},{"id":"6a703416.c5702c","type":"ui_button","z":"a400a6e7.e01ea8","name":"","group":"7499c6af.dc19e8","order":1,"width":0,"height":0,"passthru":false,"label":"Take Photo","tooltip":"","color":"","bgcolor":"","icon":"","payload":"","payloadType":"str","topic":"","x":250,"y":220,"wires":[[]]},{"id":"94a581c4.52f3b","type":"camerapi-takephoto","z":"a400a6e7.e01ea8","filemode":"1","filename":"photo1.jpeg","filedefpath":"0","filepath":"/home/pi/Pictures/","fileformat":"jpeg","resolution":"10","rotation":"180","fliph":"0","flipv":"0","brightness":"50","contrast":"0","sharpness":"0","quality":"80","imageeffect":"none","exposuremode":"auto","iso":"0","agcwait":"1.0","led":"0","awb":"auto","name":"","x":640,"y":400,"wires":[["ac17f024.797e6"]]},{"id":"ac17f024.797e6","type":"debug","z":"a400a6e7.e01ea8","name":"","active":true,"tosidebar":true,"console":false,"tostatus":false,"complete":"false","statusVal":"","statusType":"auto","x":850,"y":400,"wires":[]},{"id":"485521ae.5303","type":"mqtt out","z":"a400a6e7.e01ea8","name":"","topic":"Image","qos":"","retain":"","broker":"8fd9614d.29c4f","x":630,"y":340,"wires":[]},{"id":"86a0f299.4914d","type":"delay","z":"a400a6e7.e01ea8","name":"","pauseType":"delay","timeout":"2","timeoutUnits":"seconds","rate":"1","nbRateUnits":"1","rateUnits":"second","randomFirst":"1","randomLast":"5","randomUnits":"seconds","drop":false,"x":440,"y":220,"wires":[[]]},{"id":"17d08f88.c9673","type":"delay","z":"a400a6e7.e01ea8","name":"","pauseType":"rate","timeout":"5","timeoutUnits":"seconds","rate":"1","nbRateUnits":"10","rateUnits":"second","randomFirst":"1","randomLast":"5","randomUnits":"seconds","drop":true,"x":400,"y":400,"wires":[["94a581c4.52f3b","485521ae.5303"]]},{"id":"f3ec7454.63e1f8","type":"mqtt-broker","name":"Wemos","broker":"localhost","port":"1883","clientid":"","usetls":false,"compatmode":false,"keepalive":"60","cleansession":true,"birthTopic":"","birthQos":"0","birthPayload":"","closeTopic":"","closeQos":"0","closePayload":"","willTopic":"","willQos":"0","willPayload":""},{"id":"7499c6af.dc19e8","type":"ui_group","name":"Default","tab":"8d954983.d0c018","order":1,"disp":true,"width":"6","collapse":false},{"id":"8fd9614d.29c4f","type":"mqtt-broker","name":"PC","broker":"127.0.0.1","port":"1883","clientid":"","usetls":false,"compatmode":false,"keepalive":"60","cleansession":true,"birthTopic":"","birthQos":"0","birthPayload":"","closeTopic":"","closeQos":"0","closePayload":"","willTopic":"","willQos":"0","willPayload":""},{"id":"8d954983.d0c018","type":"ui_tab","name":"Home","icon":"dashboard","disabled":false,"hidden":false}]