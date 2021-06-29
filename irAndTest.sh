NAME="slope"
echo $NAME
./cs8803_bin/tigerc -i tests/phase2/files/$NAME.tiger --ir
java -jar tigerc-ir.jar -r tests/phase2/files/$NAME.ir
echo "----------VS---------"
cat tests/phase2/files/$NAME.output
