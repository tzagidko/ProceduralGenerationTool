// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "GeneratingTool.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;
UCLASS()
class PROCEDURALGENERATION_API AGeneratingTool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneratingTool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UMaterialInterface*Material;
	UPROPERTY(EditAnywhere, Meta=(ClampMin=0))
	int XSize=0;
	UPROPERTY(EditAnywhere, Meta=(ClampMin=0))
	int YSize=0;
	UPROPERTY(EditAnywhere, Meta=(ClampMin=0))
	float ZMultiplier=1.0f;
	UPROPERTY(EditAnywhere, Meta=(ClampMin=0))
	float NoiseScale=1.0f;
	UPROPERTY(EditAnywhere, Meta=(ClampMin=0.00001))
	int Scale=0;
	UPROPERTY(EditAnywhere, Meta=(ClampMin=0.00001))
	int UVScale=0;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
private:
	
 UProceduralMeshComponent*ProceduralMesh;
	
	TArray<FVector>Vertices;

	TArray<int>Triangles;

	TArray<FVector2D>UV0;
	TArray<FVector> Normals;
	TArray<struct FProcMeshTangent> Tangents;
	void CreateVertices();
	void CreateTriangles();
};
