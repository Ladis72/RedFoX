

CREATE TABLE "lin_alb_pro" (
  "id" int(11) NOT NULL,
  "id_cab" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cDescripcion" varchar(50)   DEFAULT NULL,
  "rCoste" real  ,
  "nDto" double DEFAULT NULL,
  "rPvp1" real  ,
  "rPvp2" real  ,
  "rPvp3" real  ,
  "nIva" double DEFAULT NULL,
  "nCantidad" double DEFAULT NULL,
  "rTotal" real  ,
  "rDto" real  ,
  "rSUBTOTAL" real  ,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "lin_fac_pro" (
  "Id" int(11) NOT NULL,
  "Id_Cab" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cDescripcion" varchar(50)   DEFAULT NULL,
  "nCantidad" double DEFAULT NULL,
  "rCosteBruto" real  ,
  "nPorcDto" double DEFAULT NULL,
  "rDto" real  ,
  "rCoste" real  ,
  "nPorcIva" double DEFAULT NULL,
  "rIva" real  ,
  "rTotal" real  ,
  "nPedido" int(11) DEFAULT NULL,
  PRIMARY KEY ("Id")
)  ;

CREATE TABLE "cab_alb" (
  "id" int(11) NOT NULL  ,
  "nAlbaran" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "cPedidoCli" varchar(20)   DEFAULT NULL,
  "id_Cliente" int(11) DEFAULT NULL,
  "cCodigoCliente" varchar(10)   DEFAULT NULL,
  "cCliente" varchar(75)   DEFAULT NULL,
  "dDireccion" varchar(45)   DEFAULT NULL,
  "cDireccion2" varchar(45)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPais" varchar(40)   DEFAULT NULL,
  "cCif" varchar(13)   DEFAULT NULL,
  "lRecargoEquivalencia" tinyint(4) DEFAULT NULL,
  "rSubtotal" decimal(8,2) DEFAULT NULL,
  "rDto" decimal(8,2) DEFAULT NULL,
  "nPorcentajeDto" decimal(5,2) DEFAULT NULL,
  "rBase1" decimal(8,2) DEFAULT NULL,
  "rBase2" decimal(8,2) DEFAULT NULL,
  "rBase3" decimal(8,2) DEFAULT NULL,
  "rBase4" decimal(8,2) DEFAULT NULL,
  "nPorcentajeIva1" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIva2" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIva3" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIva4" decimal(5,2) DEFAULT NULL,
  "rImporteIva1" decimal(8,2) DEFAULT NULL,
  "rImporteIva2" decimal(8,2) DEFAULT NULL,
  "rImporteIva3" decimal(8,2) DEFAULT NULL,
  "rImporteIva4" decimal(8,2) DEFAULT NULL,
  "nPorcentajeRecargoEq1" decimal(5,2) DEFAULT NULL,
  "nPorcentajeRecargoEq2" decimal(5,2) DEFAULT NULL,
  "nPorcentajeRecargoEq3" decimal(5,2) DEFAULT NULL,
  "nPorcentajeRecargoEq4" decimal(5,2) DEFAULT NULL,
  "rImporteRecargoEq1" decimal(8,2) DEFAULT NULL,
  "rImporteRecargoEq2" decimal(8,2) DEFAULT NULL,
  "rImporteRecargoEq3" decimal(8,2) DEFAULT NULL,
  "rImporteRecargoEq4" decimal(8,2) DEFAULT NULL,
  "rTotal1" decimal(8,2) DEFAULT NULL,
  "rTotal2" decimal(8,2) DEFAULT NULL,
  "rTotal3" decimal(8,2) DEFAULT NULL,
  "rTotal4" decimal(8,2) DEFAULT NULL,
  "rBaseTotal" decimal(8,2) DEFAULT NULL,
  "rIvaTotal" decimal(8,2) DEFAULT NULL,
  "rRecargoEqTotal" decimal(8,2) DEFAULT NULL,
  "rTotalAlbaran" decimal(8,2) DEFAULT NULL,
  "lImpreso" tinyint(4) DEFAULT NULL,
  "lFacturado" tinyint(4) DEFAULT NULL,
  "nFactura" int(11) DEFAULT NULL,
  "cSerieFactura" varchar(4)   DEFAULT NULL,
  "dFechaFactura" date DEFAULT NULL,
  "tComentario" text  ,
  "rACuenta" decimal(8,2) DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "reservas" (
  "id" int(11) NOT NULL,
  "nReserva" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "id_cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  "cDireccion" varchar(40)   DEFAULT NULL,
  "cDireccion2" varchar(40)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(30)   DEFAULT NULL,
  "cTelefono1" varchar(20)   DEFAULT NULL,
  "cTelefono2" varchar(20)   DEFAULT NULL,
  "dFechaLimite" date DEFAULT NULL,
  "rImporte" real  ,
  "rPendiente" real  ,
  "rEntregado" real  ,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "clientes" (
  "id" int(11) NOT NULL  ,
  "cCodigoCliente" varchar(10)   DEFAULT NULL,
  "cApellido1" varchar(25)   DEFAULT NULL,
  "cApellido2" varchar(25)   DEFAULT NULL,
  "cNombre" varchar(25)   DEFAULT NULL,
  "cNombreFiscal" varchar(75)   DEFAULT NULL,
  "cNombreComercial" varchar(75)   DEFAULT NULL,
  "cPersonaContacto" varchar(50)   DEFAULT NULL,
  "cCifNif" varchar(13)   DEFAULT NULL,
  "cDireccion1" varchar(50)   DEFAULT NULL,
  "cDireccion2" varchar(50)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(40)   DEFAULT NULL,
  "cTelefono1" varchar(20)   DEFAULT NULL,
  "cTelefono2" varchar(20)   DEFAULT NULL,
  "cFax" varchar(20)   DEFAULT NULL,
  "cMovil" varchar(20)   DEFAULT NULL,
  "cEmail" varchar(75)   DEFAULT NULL,
  "cWeb" varchar(75)   DEFAULT NULL,
  "cDireccionFactura1" varchar(50)   DEFAULT NULL,
  "cDireccionFactura2" varchar(10)   DEFAULT NULL,
  "cCPFactura" varchar(5)   DEFAULT NULL,
  "cPoblacionFactura" varchar(50)   DEFAULT NULL,
  "cProvinciaFactura" varchar(25)   DEFAULT NULL,
  "cPaisFactura" varchar(45)   DEFAULT NULL,
  "cDireccionAlmacen" varchar(50)   DEFAULT NULL,
  "cDireccionAlmacen2" varchar(50)   DEFAULT NULL,
  "cCPAlmacen" varchar(5)   DEFAULT NULL,
  "cPoblacionAlmacen" varchar(50)   DEFAULT NULL,
  "cProvinciaAlmacen" varchar(25)   DEFAULT NULL,
  "cPaisAlmacen" varchar(45)   DEFAULT NULL,
  "dFechaAlta" date DEFAULT NULL,
  "dFechaUltimaCompra" date DEFAULT NULL,
  "rAcumuladoVentas" decimal(8,2) DEFAULT NULL,
  "rVentasEjercicio" decimal(8,2) DEFAULT NULL,
  "rRiesgoMaximo" decimal(8,2) DEFAULT NULL,
  "rDeudaActual" decimal(8,2) DEFAULT NULL,
  "tComentarios" text  ,
  "lBloqueado" tinyint(4) DEFAULT NULL,
  "tComentarioBloqueo" text  ,
  "nPorcDtoCliente" decimal(5,2) DEFAULT NULL,
  "lRecargoEquivalencia" tinyint(4) DEFAULT NULL,
  "cCuentaContable" varchar(10)   DEFAULT NULL,
  "cCuentaIvaRepercutido" varchar(10)   DEFAULT NULL,
  "cCuentaDeudas" varchar(10)   DEFAULT NULL,
  "cCuentaCobros" varchar(10)   DEFAULT NULL,
  "cFormaPago" varchar(30)   DEFAULT NULL,
  "nDiapago1" int(11) DEFAULT NULL,
  "nDiaPago2" int(11) DEFAULT NULL,
  "nTarifaCliente" int(11) DEFAULT NULL,
  "rImporteACuenta" decimal(8,2) DEFAULT NULL,
  "rVales" decimal(8,2) DEFAULT NULL,
  "cCentidadBancaria" varchar(4)   DEFAULT NULL,
  "cOficinaBancaria" varchar(4)   DEFAULT NULL,
  "cDC" varchar(2)   DEFAULT NULL,
  "cCuentaCorriente" varchar(10)   DEFAULT NULL,
  "dFechaNacimiento" date DEFAULT NULL,
  "rImportePendiente" decimal(8,2) DEFAULT NULL,
  "cTipoCliente" text DEFAULT NULL,
  "cAccesoWeb" varchar(50)   DEFAULT NULL,
  "cPasswordWeb" varchar(50)   DEFAULT NULL,
  PRIMARY KEY ("id")
) ;

CREATE TABLE "lin_fac" (
  "id" int(11) NOT NULL,
  "id_Cab" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "nCantidad" double DEFAULT NULL,
  "cDescripcion" text  ,
  "rPvp" real  ,
  "nDto" double DEFAULT NULL,
  "rDto" real  ,
  "rSubotal" real  ,
  "rTotal" real  ,
  "nPorcIva" double DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "lin_tpv" (
  "id" int(11) NOT NULL  ,
  "id_Cab" int(11) DEFAULT NULL,
  "id_Articulo" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cDescripcion" varchar(50)   DEFAULT NULL,
  "rPvp" decimal(8,2) DEFAULT NULL,
  "nCantidad" decimal(10,2) DEFAULT NULL,
  "rImporte" decimal(8,2) DEFAULT NULL,
  "nPorcentajeIva" decimal(5,2) DEFAULT NULL,
  "nPorcDto" decimal(5,2) DEFAULT NULL,
  "nTotal" decimal(8,2) DEFAULT NULL,
  "cTipo" varchar(15)   DEFAULT NULL,
  "rSubTotal" decimal(8,2) DEFAULT NULL,
  "dFechaLinea" date DEFAULT NULL,
  PRIMARY KEY ("id")
) ;

CREATE TABLE "dependient" (
  "ID" int(11) NOT NULL,
  "cCodigo" varchar(10)   DEFAULT NULL,
  "cNombre" varchar(50)   DEFAULT NULL,
  "cDireccion" varchar(50)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "dFechaNacimiento" date DEFAULT NULL,
  "cTelefono1" varchar(20)   DEFAULT NULL,
  "cTelefono2" varchar(20)   DEFAULT NULL,
  "cMovil" varchar(20)   DEFAULT NULL,
  "cNombrePariente" varchar(50)   DEFAULT NULL,
  "cPassword" varchar(10)   DEFAULT NULL,
  "rCosteHora" real  ,
  "rCosteHoraExtra" real  ,
  "dFechaAlta" date DEFAULT NULL,
  "dFinContrato" date DEFAULT NULL,
  "cCategoria" varchar(20) , DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "Alb_pro" (
  "id" int(11) NOT NULL  ,
  "cAlbaran" varchar(25)   DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "id_Proveedor" int(11) DEFAULT NULL,
  "cProveedor" varchar(40)   DEFAULT NULL,
  "cCifProveedor" varchar(15)   DEFAULT NULL,
  "rTotal1" decimal(8,2) DEFAULT NULL,
  "rTotal2" decimal(8,2) DEFAULT NULL,
  "rTotal3" decimal(8,2) DEFAULT NULL,
  "rTotal4" decimal(8,2) DEFAULT NULL,
  "nIva1" decimal(5,2) DEFAULT NULL,
  "nIva2" decimal(5,2) DEFAULT NULL,
  "nIva3" decimal(5,2) DEFAULT NULL,
  "nIva4" decimal(5,2) DEFAULT NULL,
  "rIva1" decimal(8,2) DEFAULT NULL,
  "rIva2" decimal(8,2) DEFAULT NULL,
  "rIva3" decimal(8,2) DEFAULT NULL,
  "rIva4" decimal(8,2) DEFAULT NULL,
  "rBase1" decimal(8,2) DEFAULT NULL,
  "rBase2" decimal(8,2) DEFAULT NULL,
  "rBase3" decimal(8,2) DEFAULT NULL,
  "rBase4" decimal(8,2) DEFAULT NULL,
  "cFactura" varchar(25)   DEFAULT NULL,
  "rBaseTotal" decimal(8,2) DEFAULT NULL,
  "rIvaTotal" decimal(8,2) DEFAULT NULL,
  "rTotal" decimal(8,2) DEFAULT NULL,
  "tComentario" text  ,
  "nPedido" int(11) DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "vales" (
  "id" int(11) NOT NULL,
  "nNumero" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dVto" date DEFAULT NULL,
  "cDependient" varchar(40)   DEFAULT NULL,
  "rImporte" real  ,
  "IdTicket" int(11) DEFAULT NULL,
  "Id_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  "lPagado" tinyint(4) DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "lin_ped_pro" (
  "id" int(11) NOT NULL,
  "Id_Cab" int(11) DEFAULT NULL,
  "Id_Articulo" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cDescripcion" text  ,
  "nCantidad" decimal(8,2) DEFAULT NULL,
  "rCosteBruto" real  ,
  "rSubtotal" real  ,
  "nPorcDto" double DEFAULT NULL,
  "nDto" real  ,
  "nPorcIva" double DEFAULT NULL,
  "rIVA" real  ,
  "rTotal" real  ,
  "rTarifa1" real  ,
  "nMargen1" double DEFAULT NULL,
  "rTarifa2" real  ,
  "nMargen2" double DEFAULT NULL,
  "rTarifa3" real  ,
  "nMargen3" double DEFAULT NULL,
  "nCantidadRecibida" double DEFAULT NULL,
  "lRecibido" int(4) DEFAULT NULL,
  "lTraspasado" int(4) DEFAULT NULL,
  "cTalla" varchar(15)   DEFAULT NULL,
  "cColor" varchar(25)   DEFAULT NULL,
  "cCodigoInterno" varchar(13)   DEFAULT NULL,
  "nEtiquetas" int(11) DEFAULT NULL,
  "lOK" int(4) DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "recibos" (
  "Id" int(11) NOT NULL,
  "dFecha" date DEFAULT NULL,
  "dFechaCobro" date DEFAULT NULL,
  "cDescripcionFecha1" varchar(150)   DEFAULT NULL,
  "cDescripcionFecha2" varchar(150)   DEFAULT NULL,
  "cLocalidad" varchar(50)   DEFAULT NULL,
  "nRecibo" int(11) DEFAULT NULL,
  "Id_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  "cDireccion1" varchar(45)   DEFAULT NULL,
  "cDireccion2" varchar(45)   DEFAULT NULL,
  "cCp" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(25)   DEFAULT NULL,
  "cConcepto" varchar(254)   DEFAULT NULL,
  "rImporte" real  ,
  "cImporte" text(254)   DEFAULT NULL,
  "cDescripcionEntidad" varchar(100)   DEFAULT NULL,
  "cDescripcionOficina" varchar(100)   DEFAULT NULL,
  "cEntidad" varchar(4)   DEFAULT NULL,
  "cOficina" varchar(4)   DEFAULT NULL,
  "cDC" varchar(2)   DEFAULT NULL,
  "cCuenta" varchar(10)   DEFAULT NULL,
  "lCobrado" tinyint(4) DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;



CREATE TABLE "FormPago" (
  "id" int(11) NOT NULL,
  "cCodigo" varchar(3)   DEFAULT NULL,
  "cFormapago" varchar(50)   DEFAULT NULL,
  "nDiaPago1" int(11) DEFAULT NULL,
  "nDiaPago2" int(11) DEFAULT NULL,
  "nDiaPago3" int(11) DEFAULT NULL,
  "nDiaPago4" int(11) DEFAULT NULL,
  "nDias1" int(11) DEFAULT NULL,
  "nDias2" int(11) DEFAULT NULL,
  "nDias3" int(11) DEFAULT NULL,
  "nDias4" int(11) DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "tareas" (
  "id" int(11) NOT NULL,
  "cTarea" varchar(45)   DEFAULT NULL,
  "cAvisarA" varchar(2)   DEFAULT NULL,
  "nDiasFecha" int(11) DEFAULT NULL,
  "lCobros" tinyint(4) DEFAULT NULL,
  "lPagos" tinyint(4) DEFAULT NULL,
  "lObligacionesTributarias" tinyint(4) DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;
CREATE TABLE "histoart" (
  "Id" int(11) NOT NULL,
  "Id_Articulo" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "nCantidad" double DEFAULT NULL,
  "rImporte" real DEFAULT 0  ,
  "cNombreUsuario" varchar(50)   DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "cab_pre" (
  "id" int(11) NOT NULL  ,
  "nPresupuesto" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dValidoHasta" date DEFAULT NULL,
  "id_Cliente" int(11) DEFAULT NULL,
  "cCodigoCliente" varchar(10)   DEFAULT NULL,
  "cCliente" varchar(75)   DEFAULT NULL,
  "cCif" varchar(13)   DEFAULT NULL,
  "cDireccion" varchar(50)   DEFAULT NULL,
  "cDireccion2" varchar(50)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(40)   DEFAULT NULL,
  "cTelefono" varchar(20)   DEFAULT NULL,
  "cMovil" varchar(20)   DEFAULT NULL,
  "cFax" varchar(20)   DEFAULT NULL,
  "nDto" decimal(5,2) DEFAULT NULL,
  "tComentarios" text  ,
  "rImporte" decimal(8,2) DEFAULT NULL,
  "rSubtotal" decimal(8,2) DEFAULT NULL,
  "rDescuento" decimal(8,2) DEFAULT NULL,
  "rTotal" decimal(8,2) DEFAULT NULL,
  "lImpreso" tinyint(4) DEFAULT NULL,
  "lAprovado" tinyint(4) DEFAULT NULL,
  "dFechaAprobacion" date DEFAULT NULL,
  "rImporteFactura" decimal(8,2) DEFAULT NULL,
  "rImportePendiente" decimal(8,2) DEFAULT NULL,
  "nFactura" int(11) DEFAULT NULL,
  "nAlbaran" int(11) DEFAULT NULL,
  "nPedido" int(11) DEFAULT NULL,
  "id_FormaPago" int(11) DEFAULT NULL,
  "cCodigoFormaPago" varchar(3)   DEFAULT NULL,
  "cDescripcionFormaPago" varchar(70)   DEFAULT NULL,
  "tLugarEntrega" text  ,
  "cAtencionde" varchar(50)   DEFAULT NULL,
  "rImporte1" decimal(8,2) DEFAULT NULL,
  "rImporte2" decimal(8,2) DEFAULT NULL,
  "rImporte3" decimal(8,2) DEFAULT NULL,
  "rImporte4" decimal(8,2) DEFAULT NULL,
  "nIva1" decimal(5,2) DEFAULT NULL,
  "nIva2" decimal(5,2) DEFAULT NULL,
  "nIva3" decimal(5,2) DEFAULT NULL,
  "nIva4" decimal(5,2) DEFAULT NULL,
  "rIva1" decimal(8,2) DEFAULT NULL,
  "rIva2" decimal(8,2) DEFAULT NULL,
  "rIva3" decimal(8,2) DEFAULT NULL,
  "rIva4" decimal(8,2) DEFAULT NULL,
  "nRecargoEquivalencia1" decimal(5,2) DEFAULT NULL,
  "nRecargoEquivalencia2" decimal(5,2) DEFAULT NULL,
  "nRegargoEquivalencia3" decimal(5,2) DEFAULT NULL,
  "nRecargoEquivalencia4" decimal(5,2) DEFAULT NULL,
  "rRec1" decimal(8,2) DEFAULT NULL,
  "rRec2" decimal(8,2) DEFAULT NULL,
  "rRec3" decimal(8,2) DEFAULT NULL,
  "rRec4" decimal(8,2) DEFAULT NULL,
  "rTotal1" decimal(8,2) DEFAULT NULL,
  "rTotal2" decimal(8,2) DEFAULT NULL,
  "rTotal3" decimal(8,2) DEFAULT NULL,
  "rTotal4" decimal(8,2) DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;
CREATE TABLE "clientes_entregas" (
  "Id" int(11) NOT NULL,
  "Id_Cliente" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "rImporte" real  ,
  "nDocumento" int(11) DEFAULT NULL,
  "cTipo" varchar(30)   DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "lin_res" (
  "Id" int(11) NOT NULL,
  "Id_Cab" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cDescripcion" varchar(50)   DEFAULT NULL,
  "nCantidad" int(11) DEFAULT NULL,
  "rImporte" real  ,
  "rTotal" real  ,
  "Id_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(40)   DEFAULT NULL,
  "dFechaReserva" date DEFAULT NULL,
  "dReservadoHasta" date DEFAULT NULL,
  "nDto" double DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "conceptostallas" (
  "Id" int(11) NOT NULL,
  "cConcepto" varchar(30)   DEFAULT NULL,
  PRIMARY KEY ("Id")
)  ;

CREATE TABLE "ped_pro" (
  "Id" int(11) NOT NULL,
  "nPedido" int(11) DEFAULT NULL,
  "cSerie" varchar(6)   DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dRecepcion" date DEFAULT NULL,
  "Id_Proveedor" int(11) DEFAULT NULL,
  "cCodigoProveedor" varchar(10)   DEFAULT NULL,
  "cProveedor" varchar(50)   DEFAULT NULL,
  "cDireccion1" varchar(45)   DEFAULT NULL,
  "cDireccion2" varchar(45)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(30)   DEFAULT NULL,
  "cCifNif" varchar(15)   DEFAULT NULL,
  "rBase" real  ,
  "rSubotal" real  ,
  "rDto" real  ,
  "nIVA" real  ,
  "rRecTotal" real  ,
  "rTotal" real  ,
  "lEnviado" tinyint(4) DEFAULT NULL,
  "lRecibido" tinyint(4) DEFAULT NULL,
  "lRecibidoCompleto" tinyint(4) DEFAULT NULL,
  "lGeneroPendiente" tinyint(4) DEFAULT NULL,
  "tComentario" text  ,
  "rBase1" real  ,
  "rBase2" real  ,
  "rBase3" real  ,
  "rBase4" real  ,
  "nPorcIva1" double DEFAULT NULL,
  "nPorcIva2" double DEFAULT NULL,
  "nPorcIva3" double DEFAULT NULL,
  "nPorcIva4" double DEFAULT NULL,
  "rIVA1" real  ,
  "rIVA2" real  ,
  "rIVA3" real  ,
  "rIVA4" real  ,
  "rTotal1" real  ,
  "rTotal2" real  ,
  "rTotal3" real  ,
  "rTotal4" real  ,
  "nMargenREC1" double DEFAULT NULL,
  "nMargenREC2" double DEFAULT NULL,
  "nMargenREC3" double DEFAULT NULL,
  "nMargenREC4" double DEFAULT NULL,
  "rREC1" real  ,
  "rREC2" real  ,
  "rREC3" real  ,
  "rREC4" real  ,
  "lTraspasado" tinyint(4) DEFAULT NULL,
  "nPedidoCliente" int(11) DEFAULT NULL,
  "Id_FormaPago" int(11) DEFAULT NULL,
  "cCodigoFormaPago" varchar(3)   DEFAULT NULL,
  "cFormaPago" varchar(50)   DEFAULT NULL,
  "dVencimiento1" date DEFAULT NULL,
  "dVencimiento2" date DEFAULT NULL,
  "dVencimiento3" date DEFAULT NULL,
  "dVencimiento4" date DEFAULT NULL,

  "lPagado1" tinyint(4) DEFAULT NULL,
  "lPagado2" tinyint(4) DEFAULT NULL,
  "lPagado3" tinyint(4) DEFAULT NULL,
  "lPagado4" tinyint(4) DEFAULT NULL,
  "tComentario" text  ,
  "dFechaEntrega" date DEFAULT NULL,
  "cDireccion1" varchar(50)   DEFAULT NULL,
  "cDireccion2" varchar(50)   DEFAULT NULL,
  "cCPEntregado" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(40)   DEFAULT NULL,
  "cPaisEntrega" varchar(40)   DEFAULT NULL,
  "cNombreCliente" varchar(50)   DEFAULT NULL,
  "cHorarioActivo" varchar(30)   DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "Sectores" (
  "id" int(11) NOT NULL,
  "cSector" varchar(30)   DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;
CREATE TABLE "articulos" (
  "id" int(11) NOT NULL  ,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cCodigoBarras" varchar(13)   DEFAULT NULL,
  "cCodigoFabricante" varchar(13)   DEFAULT NULL,
  "cDescripcion" varchar(254)   DEFAULT NULL,
  "cDescripcionReducida" varchar(20)   DEFAULT NULL,
  "id_Proveedor" int(11) DEFAULT NULL,
  "cCodigoFamilia" varchar(5)   DEFAULT NULL,
  "id_Familia" int(11) DEFAULT NULL,
  "cFamilia" varchar(40)   DEFAULT NULL,
  "id_Seccion" int(11) DEFAULT NULL,
  "cSeccion" varchar(40)   DEFAULT NULL,
  "id_Subfamilia" int(11) DEFAULT NULL,
  "cSubfamilia" varchar(40)   DEFAULT NULL,
  "cCodigoIva" varchar(6)   DEFAULT NULL,
  "id_TipoIva" int(11) DEFAULT NULL,
  "rCoste" decimal(8,2) DEFAULT NULL,
  "rTarifa1" decimal(8,2) DEFAULT NULL,
  "rTarifa2" decimal(8,2) DEFAULT NULL,
  "rTarifa3" decimal(8,2) DEFAULT NULL,
  "rDto" decimal(8,2) DEFAULT NULL,
  "nDtoProveedor" decimal(5,2) DEFAULT NULL,
  "nDtoproveedor2" decimal(5,2) DEFAULT NULL,
  "nDtoProveedor3" decimal(5,2) DEFAULT NULL,
  "dUltimaCompra" date DEFAULT NULL,
  "dUltimaVenta" date DEFAULT NULL,
  "nMargen1" decimal(6,2) DEFAULT NULL,
  "nMargen2" decimal(6,2) DEFAULT NULL,
  "nMargen3" decimal(6,2) DEFAULT NULL,
  "rPrecioMedio" decimal(8,2) DEFAULT NULL,
  "nUnidadesCompradas" int(11) DEFAULT NULL,
  "rPrecioMedio2" decimal(8,2) DEFAULT NULL,
  "nUnidadesVendidas" int(11) DEFAULT NULL,
  "rPrecioMedio3" decimal(8,2) DEFAULT NULL,
  "rAcumuladoCompras" decimal(10,2) DEFAULT NULL,
  "rAcumuladoVentas" decimal(10,2) DEFAULT NULL,
  "bImagen" blob,
  "tComentario" text  ,
  "nStockMaximo" int(11) DEFAULT NULL,
  "nStockMinimo" int(11) DEFAULT NULL,
  "nStockReal" int(11) DEFAULT NULL,
  "cTipoUnidad" varchar(2)   DEFAULT NULL,
  "lControlarStock" tinyint(4) DEFAULT NULL,
  "cModelo" varchar(40)   DEFAULT NULL,
  "cTalla" varchar(15)   DEFAULT NULL,
  "cColor" varchar(20)   DEFAULT NULL,
  "cComposicion" text  ,
  "lPvpIncluyeIva" tinyint(4) DEFAULT NULL,
  "lPendienteRecibir" tinyint(4) DEFAULT NULL,
  "nCantidadPendienteRecibir" int(11) DEFAULT NULL,
  "nReservados" int(11) DEFAULT NULL,
  "lMostrarWeb" tinyint(4) DEFAULT NULL,
  "nEtiquetas" int(11) DEFAULT NULL,
  "nPaquetes" int(11) DEFAULT NULL,
  "cLocalizacion" varchar(20)   DEFAULT NULL,
 
  PRIMARY KEY ("id"),
) ;

CREATE TABLE "lin_alb" (
  "Id" int(11) NOT NULL,
  "Id_Cab" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "nCantidad" double DEFAULT NULL,
  "cDescripcion" text  ,
  "rPvp" real  ,
  "rSubTotal" real  ,
  "nPorcDto" double DEFAULT NULL,
  "nDto" real  ,
  "nPorcIva" double DEFAULT NULL,
  "nTotal" real  ,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "familias" (
  "Id" int(11) NOT NULL,
  "cCodigo" varchar(5)   DEFAULT NULL,
  "cFamilia" varchar(50)   DEFAULT NULL,
  "Id_Seccion" int(11) DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "proveedores" (
  "id" int(11) NOT NULL  ,
  "cCodigo" int(11) DEFAULT NULL,
  "cProveedor" varchar(50)   DEFAULT NULL,
  "cCif" varchar(15)   DEFAULT NULL,
  "cDireccion1" varchar(45)   DEFAULT NULL,
  "cDireccion2" varchar(45)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(40)   DEFAULT NULL,
  "cTelefono1" varchar(18)   DEFAULT NULL,
  "cTelefono2" varchar(18)   DEFAULT NULL,
  "cTelefono3" varchar(18)   DEFAULT NULL,
  "cFax" varchar(18)   DEFAULT NULL,
  "cMovil" varchar(18)   DEFAULT NULL,
  "cEMail" varchar(50)   DEFAULT NULL,
  "cWeb" varchar(50)   DEFAULT NULL,
  "cPersonaContacto" varchar(50)   DEFAULT NULL,
  "cDiaCobro" int(11) DEFAULT NULL,
  "cDireccionAlmacen" varchar(45)   DEFAULT NULL,
  "cCPAlmacen" varchar(5)   DEFAULT NULL,
  "cPoblacionAlmacen" varchar(50)   DEFAULT NULL,
  "cProvinciaAlmacen" varchar(25)   DEFAULT NULL,
  "cPaisAlmacen" varchar(40)   DEFAULT NULL,
  "cTelefonoAlmacen" varchar(18)   DEFAULT NULL,
  "cFaxAlmacen" varchar(18)   DEFAULT NULL,
  "cCodigoFormaPago" varchar(3)   DEFAULT NULL,
  "cFechaUltimaCompra" date DEFAULT NULL,
  "rAcumuladoCompras" real DEFAULT NULL,
  "cEntidadBancariaProveedor" varchar(4)   DEFAULT NULL,
  "cOficinaBancariaProveedor" varchar(4)   DEFAULT NULL,
  "cDCProveedor" varchar(2)   DEFAULT NULL,
  "cCCProveedor" varchar(10)   DEFAULT NULL,
  "cEntidadPagoProveedor" varchar(4)   DEFAULT NULL,
  "cOficinaPagoProveedor" varchar(4)   DEFAULT NULL,
  "cDCPagoProveedor" varchar(4)   DEFAULT NULL,
  "cCuentaPagoProveedor" varchar(10)   DEFAULT NULL,
  "cCuentaIvaSoportado" varchar(10)   DEFAULT NULL,
  "rRetencionIRPF" real DEFAULT NULL,
  "nTipoRetencion" int(11) DEFAULT NULL,
  "cCuentaAplicacion" varchar(10)   DEFAULT NULL,
  "cCuentaPagos" varchar(10)   DEFAULT NULL,
  "tComentarios" text  ,
  "nDto" double DEFAULT NULL,
  "dFechaAlta" date DEFAULT NULL,
  "rDeudaMaxima" real DEFAULT NULL,
  "rDeudaActual" real DEFAULT NULL,
  "lRecargoEquivalencia" int(4) DEFAULT NULL,
  "tTextoparaPedidos" text  ,
  PRIMARY KEY ("id")
) ;

CREATE TABLE "clientes_deuda" (
  "Id" int(11) NOT NULL,
  "Id_Cliente" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dVencimiento" date DEFAULT NULL,
  "cDocumento" int(11) DEFAULT NULL,
  "Id_Ticket" int(11) DEFAULT NULL,
  "Id_Factura" int(11) DEFAULT NULL,
  "nTipo" int(11) DEFAULT NULL,
  "rImporte" real  ,
  "rPagado" real  ,
  "rPendienteCobro" real  ,
  "cEntidad" varchar(4)   DEFAULT NULL,
  "cOficina" varchar(4)   DEFAULT NULL,
  "cDC" varchar(2)   DEFAULT NULL,
  "cCuenta" varchar(10)   DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "devoluciones" (
  "id" int(11) NOT NULL,
  "nTicket" int(11) DEFAULT NULL,
  "dFechaDevolucion" date DEFAULT NULL,
  "cAtendidoPor" varchar(40)   DEFAULT NULL,
  "id_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  "tComentarios" text  ,
  "cCodArticulo" varchar(30)   DEFAULT NULL,
  "cDescArticulo" varchar(45)   DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "subfamilias" (
  "Id" int(11) NOT NULL,
  "cSubfamilia" varchar(40)   DEFAULT NULL,
  "Id_Familia" int(11) DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "lin_pre" (
  "Id" int(11) NOT NULL,
  "Id_Cab" int(11) DEFAULT NULL,
  "cCodigo" varchar(13)   DEFAULT NULL,
  "cDescripcion" text  ,
  "nCantidad" double DEFAULT NULL,
  "rPvp" real  ,
  "rSubotal" real  ,
  "nPorcDto" double DEFAULT NULL,
  "rDto" real  ,
  "rTotal" real  ,
  "nPorcIVA" double DEFAULT NULL,
  PRIMARY KEY ("ID")
)  ;
CREATE TABLE "Secciones" (
  "id" int(11) NOT NULL,
  "cSeccion" varchar(40)   DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "cierrecaja" (
  "id" int(11) NOT NULL,
  "dFechaCierre" date DEFAULT NULL,
  "rDeudas" real DEFAULT NULL,
  "rEntregasACuenta" real DEFAULT NULL,
  "rValesEmitidos" real DEFAULT NULL,
  "lCajaCerrada" int(11) DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "Agenda" (
  "id" int(11) NOT NULL  ,
  "dFecha" date DEFAULT NULL,
  "dHora" varchar(5)   DEFAULT NULL,
  "id_Usuario" int(11) DEFAULT NULL,
  "cInicio" text  ,
  "cFin" text  ,
  "cAsunto" varchar(100)   DEFAULT NULL,
  "cDescripcionAsunto" text  ,
  "cEstado" varchar(20)   DEFAULT NULL,
  "cAvisarTiempo" varchar(5)   DEFAULT NULL,
  "cImportancia" varchar(10)   DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "cajaabierta" (
  "id" int(11) NOT NULL,
  "dFechaAbertura" date DEFAULT NULL,
  "dHoraAbertura" varchar(8)   DEFAULT NULL,
  "nCaja" int(11) DEFAULT NULL,
  "id_UsuarioAbertura" int(11) DEFAULT NULL,
  "cUsuarioAbertura" varchar(50)   DEFAULT NULL,
  "id_UsuarioCierre" int(11) DEFAULT NULL,
  "cUsuarioCierre" varchar(50)   DEFAULT NULL,
  "rImporteAbertura" real DEFAULT NULL,
  "rImporteCierreAnterior" real DEFAULT NULL,
  "lCajaCerrada" int(4) DEFAULT NULL,
  "rMoneda" real DEFAULT NULL,
  "rCheque" real DEFAULT NULL,
  "rTarjeta" real DEFAULT NULL,
  "rCredito" real DEFAULT NULL,
  "rEntradasExtras" real DEFAULT NULL,
  "rSalidasExtras" real DEFAULT NULL,
  "rImportePendiente" real DEFAULT NULL,
  "rVales" real DEFAULT NULL,
  "rImporteCierre" real DEFAULT NULL,
  "rValorRealCaja" real DEFAULT NULL,
  "rDescuadre" real DEFAULT NULL,
  "rImporteACuenta" real DEFAULT NULL,
  "rImporteCambios" real DEFAULT NULL,
  "rValesEmitidos" real DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "fac_pro" (
  "Id" int(11) NOT NULL  ,
  "cFactura" varchar(25)   DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dRecepcion" date DEFAULT NULL,
  "cPedido" varchar(20) DEFAULT NULL,
  "Id_Proveedor" int(11) DEFAULT NULL,
  "cProveedor" varchar(40)   DEFAULT NULL,
  "cCifProveedor" varchar(15)   DEFAULT NULL,
  "lRetencionIRPF" int(4) DEFAULT NULL,
  "lRecargoEquivalencia" int(4) DEFAULT NULL,
  "rBase1" real DEFAULT NULL,
  "rBase2" double DEFAULT NULL,
  "rBase3" double DEFAULT NULL,
  "rBase4" double DEFAULT NULL,
  "nPorcIva1" double DEFAULT NULL,
  "nPorcIva2" double DEFAULT NULL,
  "nPorcIva3" double DEFAULT NULL,
  "nPorcIva4" double DEFAULT NULL,
  "rIVA1" double DEFAULT NULL,
  "rIVA2" double DEFAULT NULL,
  "rIVA3" double DEFAULT NULL,
  "rIVA4" double DEFAULT NULL,
  "nREC1" double DEFAULT NULL,
  "nREC2" double DEFAULT NULL,
  "nREC3" double DEFAULT NULL,
  "nREC4" double DEFAULT NULL,
  "rREC1" double DEFAULT NULL,
  "rREC2" double DEFAULT NULL,
  "rREC3" double DEFAULT NULL,
  "rREC4" double DEFAULT NULL,
  "rTotal1" double DEFAULT NULL,
  "rTotal2" double DEFAULT NULL,
  "rTotal3" double DEFAULT NULL,
  "rTotal4" double DEFAULT NULL,
  "rTotalBase" double DEFAULT NULL,
  "rTotalIVA" double DEFAULT NULL,
  "rTotalRetencion" double DEFAULT NULL,
  "rTotalRecargoEq" double DEFAULT NULL,
  "rTotal" double DEFAULT NULL,
  "cFormaPago" varchar(3)   DEFAULT NULL,
  "nDiaPago1" date DEFAULT NULL,
  "nDiaPago2" date DEFAULT NULL,
  "nDiaPago3" date DEFAULT NULL,
  "nDiaPago4" date DEFAULT NULL,
  "rImportePagadoTotal" double DEFAULT NULL,
 
  "Id_TipoGasto" int(11) DEFAULT NULL,
  "cTipoGasto" varchar(40)   DEFAULT NULL,
  "tComentario" text  ,
  "lPagado" tinyint(4) DEFAULT NULL,
  "rImporteDeudaPendiente" double DEFAULT NULL,
  "cCAlbaran" varchar(25)   DEFAULT NULL,
  PRIMARY KEY ("ID")
);

CREATE TABLE "cab_fac" (
  "id" int(11) NOT NULL  ,
  "cCodigoCliente" varchar(10)   DEFAULT NULL,
  "cFactura" varchar(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dFechaCobro" date DEFAULT NULL,
  "iId_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  "cDireccion" varchar(50)   DEFAULT NULL,
  "cDireccion2" varchar(50)   DEFAULT NULL,
  "cCp" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(40)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(30)   DEFAULT NULL,
  "cCif" varchar(15)   DEFAULT NULL,
  "lRecargoEquivalencia" tinyint(4) DEFAULT NULL,
  "rSubtotal" decimal(8,2) DEFAULT NULL,
  "nDto" decimal(5,2) DEFAULT NULL,
  "nDtoPP" decimal(5,2) DEFAULT NULL,
  "rImporteDescuento" decimal(8,2) DEFAULT NULL,
  "rImporteDescuentoPP" decimal(8,2) DEFAULT NULL,
  "rBase" decimal(8,2) DEFAULT NULL,
  "nIva" decimal(5,2) DEFAULT NULL,
  "rImporteIva" decimal(8,2) DEFAULT NULL,
  "rTotal" decimal(8,2) DEFAULT NULL,
  "lImpresa" tinyint(4) DEFAULT NULL,
  "lCobrada" tinyint(4) DEFAULT NULL,
  "lContabilizada" tinyint(4) DEFAULT NULL,
  "id_FormaPago" int(11) DEFAULT NULL,
  "cFormaPago" varchar(50)   DEFAULT NULL,
  "tComentario" text  ,
  "rBase1" decimal(8,2) DEFAULT NULL,
  "rBase2" decimal(8,2) DEFAULT NULL,
  "rBase3" decimal(8,2) DEFAULT NULL,
  "rBase4" decimal(8,2) DEFAULT NULL,
  "nPorcentajeIVA1" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIVA2" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIVA3" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIVA4" decimal(5,2) DEFAULT NULL,
  "rIVA1" decimal(8,2) DEFAULT NULL,
  "rIVA2" decimal(8,2) DEFAULT NULL,
  "rIVA3" decimal(8,2) DEFAULT NULL,
  "rIVA4" decimal(8,2) DEFAULT NULL,
  "rTotal1" decimal(8,2) DEFAULT NULL,
  "rTotal2" decimal(8,2) DEFAULT NULL,
  "rTotal3" decimal(8,2) DEFAULT NULL,
  "rTotal4" decimal(8,2) DEFAULT NULL,
  "nRec1" decimal(5,2) DEFAULT NULL,
  "nRec2" decimal(5,2) DEFAULT NULL,
  "nRec3" decimal(5,2) DEFAULT NULL,
  "nRec4" decimal(5,2) DEFAULT NULL,
  "rRecargoEq1" decimal(8,2) DEFAULT NULL,
  "rRecargoEq2" decimal(8,2) DEFAULT NULL,
  "rRecargoEq3" decimal(8,2) DEFAULT NULL,
  "rRecargoEq4" decimal(8,2) DEFAULT NULL,
  "rTotalRecargoEq" decimal(8,2) DEFAULT NULL,
  "rEntregadoaCuenta" decimal(8,2) DEFAULT NULL,
  "rImportePendiente" decimal(8,2) DEFAULT NULL,
  "cCodigoEntidad" varchar(4)   DEFAULT NULL,
  "cOficinaEntidad" varchar(4)   DEFAULT NULL,
  "cDCCuenta" varchar(2)   DEFAULT NULL,
  "cNumeroCuenta" varchar(10)   DEFAULT NULL,
  "cPedidoCliente" int(11) DEFAULT NULL,
  PRIMARY KEY ("id")
) ;

CREATE TABLE "tiposgasto" (
  "Id" int(11) NOT NULL,
  "cDescripcionTipoGasto" varchar(40)   DEFAULT NULL,
  "cComentario" text  ,
  PRIMARY KEY ("ID")
)  ;

CREATE TABLE "ObligacionesTrib" (
  "id" int(11) NOT NULL,
  "cObligacion" varchar(50)   DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "cModeloDocumento" varchar(5)   DEFAULT NULL,
  "cPeriodicidad" varchar(20)   DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;

CREATE TABLE "ped_cli" (
  "Id" int(11) NOT NULL,
  "cPedido" varchar(20) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dFechaLimiteEntrega" date DEFAULT NULL,
  "Id_Cliente" int(11) DEFAULT NULL,
  "cCodigoCliente" varchar(10)   DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  "cDireccion1" varchar(45)   DEFAULT NULL,
  "cDireccion2" varchar(45)   DEFAULT NULL,
  "cCP" varchar(5)   DEFAULT NULL,
  "cPoblacion" varchar(50)   DEFAULT NULL,
  "cProvincia" varchar(25)   DEFAULT NULL,
  "cPais" varchar(30)   DEFAULT NULL,
  "cCifNif" varchar(15)   DEFAULT NULL,
  "id_FormaPago" int   DEFAULT NULL,
  "nPorcDto" double DEFAULT NULL,
  "rBase" real  ,
  "rSubotal" real  ,
  "rDto" real  ,
  "rIVA" real  ,
  "rRecargoEqTotal" real  ,
  "rTotal" real  ,
  "lEnviado" tinyint(4) DEFAULT NULL,
  "lCompleto" tinyint(4) DEFAULT NULL,
  "lPendiente" tinyint(4) DEFAULT NULL,
  "tComentario" text  ,
  "rBase1" real  ,
  "rBase2" real  ,
  "rBase3" real  ,
  "rBase4" real  ,
  "nPorcIVA1" double DEFAULT NULL,
  "nPorcIVA2" double DEFAULT NULL,
  "nPorcIVA3" double DEFAULT NULL,
  "nPorcIVA4" double DEFAULT NULL,
  "rIVA1" real  ,
  "rIVA2" real  ,
  "rIVA3" real  ,
  "rIVA4" real  ,
  "rTotal1" real  ,
  "rTotal2" real  ,
  "rTotal3" real  ,
  "rTotal4" real  ,
  "nREC1" double DEFAULT NULL,
  "nREC2" double DEFAULT NULL,
  "nREC3" double DEFAULT NULL,
  "nREC4" double DEFAULT NULL,
  "rREC1" real  ,
  "rREC2" real  ,
  "rREC3" real  ,
  "rREC4" real  ,
  "lTraspasado" int(4) DEFAULT NULL,
  "lTraspasado2" int(4) DEFAULT NULL,
  "cDireccionEntrega1" varchar(50)   DEFAULT NULL,
  "cDireccionEntrega2" varchar(50)   DEFAULT NULL,
  "cCPEntrega" varchar(5)   DEFAULT NULL,
  "cPoblacionEntrega" varchar(50)   DEFAULT NULL,
  "cProvinciaEntrega" varchar(40)   DEFAULT NULL,
  "cPaisEntrega" varchar(25)   DEFAULT NULL,
  PRIMARY KEY ("Id")
)  ;

CREATE TABLE "histovales" (
  "ID" int(11) NOT NULL,
  "nVale" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "dVencimientoVale" date DEFAULT NULL,
  "cDependiente" varchar(40)   DEFAULT NULL,
  "rImporte" real  ,
  "Id_Ticket" int(11) DEFAULT NULL,
  "Id_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(50)   DEFAULT NULL,
  PRIMARY KEY ("Id")
)  ;

CREATE TABLE "tiposiva" (
  "Id" int(11) NOT NULL,
  "cTipo" varchar(6)   DEFAULT NULL,
  "cDescripcionTipoIVA" varchar(50)   DEFAULT NULL,
  "nIVA" double DEFAULT NULL,
  "nRegargoEquivalencia" double DEFAULT NULL,
  PRIMARY KEY ("Id")
)  ;
CREATE TABLE "tallas" (
  "Id" int(11) NOT NULL,
  "Talla" varchar(10)   DEFAULT NULL,
  "Id_ConceptoTalla" int(11) DEFAULT NULL,
  PRIMARY KEY ("Id")
)  ;

CREATE TABLE "bancos" (
  "id" int(11) NOT NULL  ,
  "cDescripcion" varchar(40)   DEFAULT NULL,
  "cEntidad" varchar(4)   DEFAULT NULL,
  "cOficina" varchar(4)   DEFAULT NULL,
  "cDc" varchar(2)   DEFAULT NULL,
  "cCuenta" varchar(10)   DEFAULT NULL,
  "rSaldo" real DEFAULT NULL,
  PRIMARY KEY ("id")
)  ;


CREATE TABLE "cab_tpv" (
  "id" int(11) NOT NULL  ,
  "nCaja" int(11) DEFAULT NULL,
  "nTicket" int(11) DEFAULT NULL,
  "dFecha" date DEFAULT NULL,
  "cHora" varchar(5)   DEFAULT NULL,
  "cUsuario" varchar(3)   DEFAULT NULL,
  "cNombreUsuario" varchar(30)   DEFAULT NULL,
  "id_Cliente" int(11) DEFAULT NULL,
  "cCliente" varchar(10)   DEFAULT NULL,
  "cNombreCliente" varchar(50)   DEFAULT NULL,
  "lticketEnEpera" tinyint(4) DEFAULT NULL,
  "lPendienteCobro" tinyint(4) DEFAULT NULL,
  "cFormaPago" varchar(30)   DEFAULT NULL,
  "cTipoTarjeta" varchar(30)   DEFAULT NULL,
  "lImpreso" tinyint(4) DEFAULT NULL,
  "rImporte" decimal(8,2) DEFAULT NULL,
  "rBase1" decimal(8,2) DEFAULT NULL,
  "rBase2" decimal(8,2) DEFAULT NULL,
  "rBase3" decimal(8,2) DEFAULT NULL,
  "rBase4" decimal(8,2) DEFAULT NULL,
  "nPorcentajeIva1" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIva2" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIva3" decimal(5,2) DEFAULT NULL,
  "nPorcentajeIva4" decimal(5,2) DEFAULT NULL,
  "rImporteIva1" decimal(8,2) DEFAULT NULL,
  "rImporteIva2" decimal(8,2) DEFAULT NULL,
  "rImporteIva3" decimal(8,2) DEFAULT NULL,
  "rImporteIva4" decimal(8,2) DEFAULT NULL,
  "rTotal1" decimal(8,2) DEFAULT NULL,
  "rTotal2" decimal(8,2) DEFAULT NULL,
  "rTotal3" decimal(8,2) DEFAULT NULL,
  "rTotal4" decimal(8,2) DEFAULT NULL,
  "rSubotal" decimal(8,2) DEFAULT NULL,
  "rDto" decimal(8,2) DEFAULT NULL,
  "nPorcentajeRe1" decimal(5,2) DEFAULT NULL,
  "nPorcentajeRe2" decimal(5,2) DEFAULT NULL,
  "nPorcentajeRe3" decimal(5,2) DEFAULT NULL,
  "nPorcentajeRe4" decimal(5,2) DEFAULT NULL,
  "rImporteRecargoEq1" decimal(8,2) DEFAULT NULL,
  "rImporteRecargoEq2" decimal(8,2) DEFAULT NULL,
  "rImporteRecargoEq3" decimal(8,2) DEFAULT NULL,
  "rImporteRecargoEq4" decimal(8,2) DEFAULT NULL,
  "rTotalRecargoEq" decimal(8,2) DEFAULT NULL,
  "rImporteTotalIva" decimal(8,2) DEFAULT NULL,
  "rCobrado" decimal(8,2) DEFAULT NULL,
  "rPendienteCobro" decimal(8,2) DEFAULT NULL,
  "rImporteEfectivo" decimal(8,2) DEFAULT NULL,
  "rImporteTarjeta" decimal(8,2) DEFAULT NULL,
  "rImporteCheque" decimal(8,2) DEFAULT NULL,
  "rImporteCredito" decimal(8,2) DEFAULT NULL,
  "rImporteDtoRedondeo" decimal(8,2) DEFAULT NULL,
  "rImporteCambio" decimal(8,2) DEFAULT NULL,
  "rEntregado" decimal(8,2) DEFAULT NULL,
  "lPasadoAlbaranFactura" tinyint(4) DEFAULT NULL,
  "nNumeroAlbaran" tinyint(4) DEFAULT NULL,
  "nNumeroFactura" tinyint(4) DEFAULT NULL,
  PRIMARY KEY ("id")
);